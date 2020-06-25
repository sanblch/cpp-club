cmake_minimum_required(VERSION 3.1.0)

project(widgets_wiggly)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)
endif()
find_package(Qt5 5.12 COMPONENTS Widgets CONFIG REQUIRED)
if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
endif()

add_executable(${PROJECT_NAME}
  dialog.cpp
  main.cpp
  wigglywidget.cpp)

if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  set_target_properties(${PROJECT_NAME}
    PROPERTIES LINK_FLAGS "-s WASM=1 -s FULL_ES2=1 -s FULL_ES3=1 -s USE_WEBGL2=1 -s EXIT_RUNTIME=1 -s ERROR_ON_UNDEFINED_SYMBOLS=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=[\"UTF16ToString\",\"stringToUTF16\"] --bind -s FETCH=1 -O2 -s ALLOW_MEMORY_GROWTH=1")
endif()

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets)
