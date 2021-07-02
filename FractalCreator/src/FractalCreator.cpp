#include "FractalCreator.h"

using namespace fractal;

FractalCreator::FractalCreator(int width, int height)
    : _width(width), _height(height), _zooms(width, height),
      _bitmap(width, height),
      _histogram(Mandelbrot::kMaxIterations, 0),
      _fractal(width * height) {

}

FractalCreator::~FractalCreator() {

}

void FractalCreator::addZoom(const Zoom &zoom) {
    _zooms.add(zoom);
}

void FractalCreator::addColorRange(double rangeEnd, const RGB &rgb) {
    _colorRanges.push_back(rangeEnd * Mandelbrot::kMaxIterations);
    _colors.push_back(rgb);

    if (_firstRange) {
        _pixelRanges.push_back(0);
    }

    _firstRange = true;
}

int FractalCreator::getRange(int iterations) const {
    int range = 0;
    for (int i = 1; i < _colorRanges.size(); i++) {
        range = i;
        if (_colorRanges[i] > iterations) {
            break;
        }

    }
    range--;

    assert(range > -1);
    assert(range < _colorRanges.size());

    return range;
}

void FractalCreator::calculateRangeTotals() {

    int rangeIndex = 0;
    for (int i = 0; i < Mandelbrot::kMaxIterations; i++) {
        int pixels = _histogram[i];
        
        if (i >= _colorRanges[rangeIndex + 1])
            rangeIndex++;

        _pixelRanges[rangeIndex] += pixels;
    }
}

void FractalCreator::drawFractal() {

    #pragma omp parallel for
    // Compute fractal values
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            double xFractal, yFractal;
            std::tie(xFractal, yFractal) = _zooms.doZoom(x, y);
            // Obtain iterations
            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            _fractal[y * _width + x] = iterations;
        }
    }

    // Fill color histogram
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            int iterations = _fractal[y * _width + x];
            // Discard runs that could not converge and reached MaxIterations
            if (iterations != Mandelbrot::kMaxIterations) {
                _histogram[iterations]++;
            }
        }
    }

    calculateRangeTotals();

    // Compute color for each pixel
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {

            int iterations = _fractal[y * _width + x];

            int range = getRange(iterations);
            int rangeTotal = _pixelRanges[range];
            int rangeStart = _colorRanges[range];

            RGB& start = _colors[range];
            RGB& end = _colors[range + 1];
            RGB diff = end - start;
            
            uint8_t r {0}, g {0}, b {0};

            if (iterations != Mandelbrot::kMaxIterations) {

                int totalPixels = 0;
                for (int i = rangeStart; i <= iterations; i++) {
                    totalPixels += _histogram[i];
                }

                r = start.r + diff.r * (double)totalPixels / rangeTotal;
                g = start.g + diff.g * (double)totalPixels / rangeTotal;
                b = start.b + diff.b * (double)totalPixels / rangeTotal;
            }

            _bitmap.setPixel(x, y, r, g, b);
        }
    }
}

void FractalCreator::writeBitmap(const std::string &filename) const {
    _bitmap.write(filename);
}
