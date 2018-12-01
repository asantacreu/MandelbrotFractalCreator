cmake_minimum_required(VERSION 3.12.4)

project(MandelbrotFractalCreator)

set (CMAKE_CXX_STANDARD 11)

set (SOURCES
     main.cpp
     Bitmap.cpp
     Mandelbrot.cpp
     ZoomList.cpp
     FractalCreator.cpp
     RGB.cpp
)


add_executable(${PROJECT_NAME} ${SOURCES})
