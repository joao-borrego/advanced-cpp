#include "FractalCreator.h"
#include "Zoom.h"
#include "RGB.h"

using namespace fractal;

int main() {

    constexpr int kHeight = 1200;
    constexpr int kWidth = 1600; 

    FractalCreator fc(kWidth, kHeight);
    
    fc.addZoom(Zoom(kWidth / 2.0, kHeight / 2.0, 4.0 / kWidth));
    fc.addZoom(Zoom(600, kHeight - 400, 0.1));
    fc.addZoom(Zoom(600, kHeight - 600, 0.1));

    fc.addColorRange(0.0, RGB(0, 0, 0));    
    fc.addColorRange(0.3, RGB(255, 0, 0));
    fc.addColorRange(0.5, RGB(255, 255, 0));
    fc.addColorRange(1.0, RGB(255, 255, 255));

    fc.drawFractal();
    fc.writeBitmap("fractal.bmp");

    return 0;
}
