
#include "FractalCreator.h"

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    FractalCreator fractalCreator(WIDTH, HEIGHT);

    fractalCreator.addZoom(Zoom(295, HEIGHT-202, 0.1));
    fractalCreator.addZoom(Zoom(312, HEIGHT-304, 0.1));

    fractalCreator.Create();

    fractalCreator.writeBitmap("test1.bmp");

	return 0;
}
