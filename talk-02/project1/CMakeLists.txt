cmake_minimum_required(VERSION 3.1.0)

project(units)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../cmake)

set(CONAN_PACKAGES_DEFAULT "boost")
set(CONAN_OPTIONS_DEFAULT "boost:shared=True")
include(packages)

add_executable(units units.cpp)
target_link_libraries(units
  CONAN_PKG::boost)
