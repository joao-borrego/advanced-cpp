#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <cstdint>
#include <vector>
#include <numeric>
#include <utility>
#include <math.h>
#include <cassert>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "RGB.h"

namespace fractal {

class FractalCreator {

private:
    int _width {0};
    int _height {0};
    ZoomList _zooms;

    Bitmap _bitmap;;
    std::vector<int> _histogram;
    std::vector<int> _fractal;

    // The Mandelbrot fractal is colored with configurable color ranges

    /// Stores the limits of the iterations ranges, each of which starts with some color
    /// and gradually changes to the next
    std::vector<int> _colorRanges;
    /// Stores the color values at the start of each range
    std::vector<RGB> _colors;
    /// Stores the total number of pixels in each range
    std::vector<int> _pixelRanges;

    bool _firstRange{false};
    /// Returns index of a color range for a given number of iterations 
    int getRange(int iterations) const;
    /// Computes the total number of pixels for each of the color ranges
    /// This is needed for gradually going from one color to another 
    void calculateRangeTotals(); 

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();

    void addZoom(const Zoom &zoom);
    // TODO
    void addColorRange(double rangeEnd, const RGB &rgb);
    void drawFractal();
    void writeBitmap(const std::string &filename) const;
};

}

#endif
