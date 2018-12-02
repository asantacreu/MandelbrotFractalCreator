#include "Bitmap.h"

#include <fstream>

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;

Bitmap::Bitmap(int width,  int height)
    : width(width),
      height(height),
      pixels(new uint8_t[width * height * 3]{})
{
    //Empty
}

Bitmap::~Bitmap() {
    //Empty
}

bool Bitmap::write(string filename) {
    BitmapFileHeader fileHeader(width, height, 3);
    BitmapInfoHeader infoHeader;

    infoHeader.width = width;
    infoHeader.height = height;

    bool fileWritten = false;

    ofstream file;
    file.open(filename, ios::out | ios::binary);

    if(file) {
        file.write((char *)&fileHeader, sizeof(fileHeader));
        file.write((char *)&infoHeader, sizeof(infoHeader));
        file.write((char *)pixels.get(), width * height * 3);

        file.close();
        if(file){
            fileWritten = true;
        }
    }

    return fileWritten;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    int pixelIndex = (x * 3) + (y * 3) * width;
    pixels[pixelIndex] = blue;
    pixels[pixelIndex + 1] = green;
    pixels[pixelIndex + 2] = red;
}
