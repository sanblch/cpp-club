cmake_minimum_required(VERSION 3.18)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../cmake)
list(APPEND CONAN_PACKAGES
  boost/1.71.0
  gtest/1.10.0
  range-v3/0.10.0)

enable_testing()
include(packages)
include(GoogleTest)

add_executable(ranges
  main.cxx)

target_compile_options(ranges PUBLIC
  -fconcepts-diagnostics-depth=2)

target_link_libraries(ranges PUBLIC
  CONAN_PKG::boost
  CONAN_PKG::range-v3)

add_executable(ranges2
  test.cxx)

target_compile_options(ranges2 PUBLIC
  -fconcepts-diagnostics-depth=2
  --std=c++20)

target_link_libraries(ranges2 PUBLIC
  CONAN_PKG::boost
  CONAN_PKG::gtest
  CONAN_PKG::range-v3)

gtest_discover_tests(ranges2)

add_executable(ranges3
  test2.cxx)

target_compile_options(ranges3 PUBLIC
  --std=c++20)
