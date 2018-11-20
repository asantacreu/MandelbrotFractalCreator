#include <iostream>
#include <cstdint>
#include <memory>
#include <utility>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;

int main() {

    const int WIDTH = 800;
    const int HEIGHT = 600;
    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 99999;
    double max = -99999;

    ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<size_t[]> fractal(new size_t[WIDTH * HEIGHT]{0});

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            pair<double, double> coords = zoomList.doZoom(x, y);
            auto iterations = Mandelbrot::getIterations(coords.first, coords.second);
            if(iterations < Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }

            fractal[x + y * WIDTH] = iterations;
        }
    }

    int total = 0;
    for(size_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }


    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            size_t iterations = fractal[x + y * WIDTH];
            if(iterations != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0.0;
                for(size_t i = 0; i <= iterations; i++) {
                    hue += ((double) histogram[i]) / total;
                }

                green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bool bitmapWritten = bitmap.write("test1.bmp");

    if(bitmapWritten){
        cout << "Finished Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }
	return 0;
}
