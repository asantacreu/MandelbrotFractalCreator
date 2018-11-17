#include <iostream>
#include "Bitmap.h"

using namespace std;

int main() {

    const int WIDTH = 800;
    const int HEIGHT = 800;
    Bitmap bitmap(WIDTH, HEIGHT);

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < WIDTH; y++) {
            bitmap.setPixel(x, y, 255, 0, 0);
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
