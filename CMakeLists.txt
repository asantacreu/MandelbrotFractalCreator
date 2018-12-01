cmake_minimum_required(VERSION 3.12.4)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(MandelbrotFractalCreatorTest ${CMAKE_BINARY_DIR}/bin/test/MandelbrotFractalCreatorTest)
