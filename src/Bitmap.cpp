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
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    fileHeader.fileSize = fileHeader.dataOffset + width * height * 3;

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

}
