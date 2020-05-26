cmake_minimum_required(VERSION 3.1.0)

project(enable_if)

set(CMAKE_CXX_STANDARD 17)

add_executable(enable_if enable_if.cpp)
add_executable(enable_if_arg enable_if_arg.cpp)
add_executable(enable_if_constexpr enable_if_constexpr.cpp)
add_executable(enable_if_custom enable_if_custom.cpp)
add_executable(enable_if_tag enable_if_tag.cpp)
add_executable(enable_if_temp enable_if_temp.cpp)
