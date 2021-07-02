#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fractal {

class Mandelbrot {
public:
    /// Maximum number of fractal algorithm iterations
    static const int kMaxIterations = 2000; 

    Mandelbrot();
    virtual ~Mandelbrot();

    static int getIterations(double x, double y);
};

}

#endif