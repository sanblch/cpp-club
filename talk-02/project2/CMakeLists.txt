cmake_minimum_required(VERSION 3.1.0)

project(units)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../cmake)

set(CONAN_PACKAGES_DEFAULT "boost")
set(CONAN_OPTIONS_DEFAULT "boost:shared=True")
include(packages)

add_executable(event-system event-system.cpp)
target_link_libraries(event-system
  CONAN_PKG::boost)
