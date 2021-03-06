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

void FractalCreator::addZoom(const Zoom &zoom) {
    zoomList.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
    ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    rangeColors.push_back(rgb);

    if(gotFirstRange){
        rangeTotals.push_back(0);
    }

    gotFirstRange = true;
}

void FractalCreator::run(string name) {
    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(name);
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

void FractalCreator::calculateRangeTotals() {
    for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = histogram[i];
        for(size_t f = 0; f < ranges.size(); f++) {
            if(i <= ranges[f + 1]) {
                rangeTotals[f] += pixels;
                break;
            }
        }
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
                size_t rangeIndex = getRange(iterations);
                RGB& startColor = rangeColors[rangeIndex];
                RGB& endColor = rangeColors[rangeIndex + 1];
                RGB colorDiff = (endColor - startColor);

                int startIterations = ranges[rangeIndex];
                int totalRangeIterations = rangeTotals[rangeIndex];

                double totalPixels = 0.0;
                for(size_t i = startIterations; i <= iterations; i++) {
                    totalPixels += (double) histogram[i];
                }
                totalPixels /= totalRangeIterations;

                red = startColor.r + colorDiff.r * totalPixels;
                green = startColor.g + colorDiff.g * totalPixels;
                blue = startColor.b + colorDiff.b * totalPixels;
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

size_t FractalCreator::getRange(int iterations) const {
    size_t rangeIndex = 0;

    for(size_t f = 0; f < ranges.size(); f++) {
        if(iterations <= ranges[f + 1]) {
            rangeIndex = f;
            break;
        }
    }

    return rangeIndex;
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


