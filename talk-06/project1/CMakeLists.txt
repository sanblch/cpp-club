cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_executable(helloworld
  main.cpp)

set_target_properties(helloworld
  PROPERTIES LINK_FLAGS "-s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0")
