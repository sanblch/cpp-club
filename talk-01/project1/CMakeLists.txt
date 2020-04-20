cmake_minimum_required(VERSION 3.2)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(range-test)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)
conan_define_targets()

add_executable(${PROJECT_NAME} range-test.cpp)
