#include "Bitmap.h"

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

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
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    fileHeader.fileSize = fileHeader.dataOffset + width * height * 3;

    infoHeader.width = width;
    infoHeader.height = height;

    return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}
