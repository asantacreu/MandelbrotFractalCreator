cmake_minimum_required(VERSION 3.12.4)
set (CMAKE_CXX_STANDARD 11)

project(MandelbrotSetImage)

set (SOURCE_FILES main.cpp)
set (SOURCE_FILES ${SOURCE_FILES} Bitmap.cpp)
set (SOURCE_FILES ${SOURCE_FILES} Mandelbrot.cpp)

add_executable(mandelbrotSet ${SOURCE_FILES})
