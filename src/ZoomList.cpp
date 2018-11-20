#include "ZoomList.h"

ZoomList::ZoomList(int width, int height)
    : width(width),
      height(height)
{
    //Empty
}

void ZoomList::Add(const Zoom &zoom) {
    zooms.push_back(zoom);
}

pair<double, double> ZoomList::doZoom(int x, int y) {
    return pair<double, double>(0, 0);
}
