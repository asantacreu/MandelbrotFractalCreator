#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

#include "BitmapInfoHeader.h"

using namespace std;

#pragma pack(2)

class BitmapFileHeader{
    public:
        BitmapFileHeader() = delete;

        BitmapFileHeader(int width, int height, int numColors) {
            dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
            fileSize = (dataOffset + width * height * numColors);
        }

        int32_t getFileSize() const{
            return fileSize;
        }

    private:
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
};

#endif // BITMAPFILEHEADER_H
