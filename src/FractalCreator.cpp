#include "FractalCreator.h"

#include <iostream>
#include <math.h>

#include "Mandelbrot.h"

using namespace std;

FractalCreator::FractalCreator(int width, int height)
    : width(width),
      height(height),
      bitmap(width, height),
      zoomList(width, height),
      histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
      fractal(new size_t[width * height]{0})
{
    addZoom(Zoom(width/2, height/2, 4.0/width));
}

FractalCreator::~FractalCreator() {
    //Empty
}

void FractalCreator::Create() {
    calculateIteration();
    calculateTotalIterations();
    drawFractal();
}

void FractalCreator::calculateIteration() {
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            pair<double, double> coords = zoomList.doZoom(x, y);
            auto iterations = Mandelbrot::getIterations(coords.first, coords.second);
            if(iterations < Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }

            fractal[x + y * width] = iterations;
        }
    }
}

void FractalCreator::calculateTotalIterations() {
    totalIterations = 0;
    for(size_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        totalIterations += histogram[i];
    }
}

void FractalCreator::drawFractal() {
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            size_t iterations = fractal[x + y * width];
            if(iterations != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0.0;
                for(size_t i = 0; i <= iterations; i++) {
                    hue += ((double) histogram[i]) / totalIterations;
                }

                green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::addZoom(const Zoom &zoom) {
    zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name) {
    bool bitmapWritten = bitmap.write(name);

    if(bitmapWritten) {
        cout << "bitmapWritten Successful" << endl;
    }
    else {
        cout << "bitmapWritten Failed" << endl;
    }
}
