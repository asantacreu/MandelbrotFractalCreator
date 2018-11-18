#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <cstdint>

class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 1000;

    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static size_t getIterations(double x, double y);
};

#endif // MANDELBROT_H
