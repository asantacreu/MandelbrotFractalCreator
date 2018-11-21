#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <memory>

#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"

using namespace std;

class FractalCreator {
    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();

        void Create();
        void addZoom(const Zoom& zoom);
        void writeBitmap(string name);

    private:
        int width;
        int height;
        Bitmap bitmap;
        ZoomList zoomList;
        unique_ptr<int[]> histogram{nullptr};
        unique_ptr<size_t[]> fractal{nullptr};
        int totalIterations{0};

        void calculateIteration();
        void calculateTotalIterations();
        void drawFractal();
};

#endif // FRACTALCREATOR_H
