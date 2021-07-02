#include <complex>
#include "Mandelbrot.h"

namespace fractal {

int Mandelbrot::getIterations(double x, double y) {

    std::complex<double> z {0};
    std::complex<double> c {x, y};

    int iterations;
    for (iterations = 0; iterations < kMaxIterations; iterations++) {
        z = z * z + c;
        if (abs(z) > 2) {
            break;
        }
    }

    return iterations;
}

}
