#include <iostream>
#include "Bitmap.h"

using namespace std;

int main() {

    Bitmap bitmap(800, 600);

    bool bitmapWritten = bitmap.write("test1.bmp");

    if(bitmapWritten){
        cout << "Finished Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }
	return 0;
}
