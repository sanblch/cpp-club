cmake_minimum_required(VERSION 3.1.0)

project(conan-test)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CONAN_PACKAGES_DEFAULT "boost json")
set(CONAN_OPTIONS_DEFAULT "boost:shared=True")
include(packages)

add_executable(conan-test conan-test.cpp)
target_link_libraries(conan-test
  CONAN_PKG::boost
  CONAN_LIB::boost_boost_serialization
  CONAN_PKG::nlohmann_json)
