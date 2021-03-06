cmake_minimum_required(VERSION 3.12.4)
include(ExternalProject)

project(MandelbrotFractalCreatorTest)

set(CMAKE_CXX_STANDARD 11)



######################################
# GOOGLE TEST DEPENDENCY
######################################

get_filename_component(DEPENDENCIES_ROOT ${PROJECT_BINARY_DIR}/ThirdPartyDependencies ABSOLUTE)

set(GOOGLE_TEST "googleTest")
set(GOOGLE_TEST_PATH "${DEPENDENCIES_ROOT}/${GOOGLE_TEST}")
set(GOOGLE_TEST_INSTALLATION_PATH "${GOOGLE_TEST_PATH}/installation")


set(cmake_googleTest_args -DCMAKE_INSTALL_PREFIX=${GOOGLE_TEST_INSTALLATION_PATH})


ExternalProject_Add(${GOOGLE_TEST}
GIT_REPOSITORY "https://github.com/google/googletest.git"
GIT_TAG "master"
CMAKE_ARGS ${cmake_googleTest_args} ${cmake_global_args}
PREFIX "${GOOGLE_TEST_PATH}"
)


include_directories(${GOOGLE_TEST_INSTALLATION_PATH}/include)
link_directories(${GOOGLE_TEST_INSTALLATION_PATH}/lib)



######################################
# MAIN TARGET
######################################

set (SOURCES
     main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} ${GOOGLE_TEST})

target_link_libraries(${PROJECT_NAME} PRIVATE
    gtest
    gmock
)
