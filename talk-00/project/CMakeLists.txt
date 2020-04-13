cmake_minimum_required(VERSION 3.2)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(pybind11-lib)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)
conan_define_targets()

# add_library(pycpp SHARED pycpp.cxx)

# set(SUFFIX ".pyd")
# if(UNIX)
#   set(SUFFIX ".so")
# endif()

# set_target_properties(pycpp PROPERTIES
#   POSITION_INDEPENDENT_CODE ON
#   PREFIX ""
#   SUFFIX ${SUFFIX})

set(pybind11_DIR ${CONAN_PYBIND11_ROOT})

find_package(pybind11)
pybind11_add_module(pycpp pycpp.cxx) # эта строка заменяет остальные закомментированные
# find_package(Python3 COMPONENTS Development Interpreter REQUIRED)

# target_link_libraries(pycpp
#   pybind11::pybind11
#   Python3::Python)

file(COPY test-pybind11.py DESTINATION ${CMAKE_BINARY_DIR}
  FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE)
install(FILES test-pybind11.py DESTINATION ${CMAKE_INSTALL_PREFIX})

if(BUILD_TESTING)
  add_subdirectory(Testing)
endif()
