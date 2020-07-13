cmake_minimum_required(VERSION 3.18)

add_executable(concept
  main.cxx)

target_compile_options(concept PUBLIC
  -fconcepts
  --std=c++1z)

add_executable(test2
  test2.cxx)

target_compile_options(test2 PUBLIC
  --std=c++20)

add_executable(test3
  test3.cxx)

target_compile_options(test3 PUBLIC
  --std=c++20)
