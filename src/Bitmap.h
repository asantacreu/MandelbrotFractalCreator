#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>

using namespace std;

class Bitmap {
    public:
        Bitmap(int width,  int height);
        virtual ~Bitmap();

        bool write(string filename);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

    private:
        int width{0};
        int height{0};

};

#endif // BITMAP_H