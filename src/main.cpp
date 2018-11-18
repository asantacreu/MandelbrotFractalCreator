#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;

int main() {

    const int WIDTH = 800;
    const int HEIGHT = 800;
    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 99999;
    double max = -99999;

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            double xFractal = ((x - WIDTH/2) / (WIDTH/2.0));
            double yFractal = ((y - HEIGHT/2) / (HEIGHT/2.0));

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            uint8_t red = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

            bitmap.setPixel(x, y, red, 0, 0);
            if(red < min){
                min = red;
            }
            if(red > max){
                max = red;
            }

        }
    }

    cout << min << ", " << max << endl;

    bool bitmapWritten = bitmap.write("test1.bmp");

    if(bitmapWritten){
        cout << "Finished Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }
	return 0;
}
