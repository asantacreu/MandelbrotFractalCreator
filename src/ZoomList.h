#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

class ZoomList {
    public:
        ZoomList(int width, int height);

        void Add(const Zoom &zoom);
        pair<double, double> doZoom(int x, int y);

    private:
        int width{0};
        int height{0};
        vector<Zoom> zooms;
};

#endif // ZOOMLIST_H
