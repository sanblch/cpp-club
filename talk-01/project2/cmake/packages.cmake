set(CONAN "conan" CACHE STRING "Conan executable")
set(CONAN_PROFILE "default" CACHE STRING "Conan profile")
set(CONAN_PACKAGES ${CONAN_PACKAGES_DEFAULT} CACHE STRING
  "Conan packages list")
set(CONAN_OPTIONS ${CONAN_OPTIONS_DEFAULT} CACHE STRING
  "Conan packages options")

string(REPLACE " " ";" CONAN_PACKAGES_LIST ${CONAN_PACKAGES})
string(REPLACE " " ";" CONAN_OPTIONS_LIST ${CONAN_OPTIONS})

foreach(package IN LISTS CONAN_PACKAGES_LIST)
  set(USE_CONAN_${package} ON BOOL)
endforeach()

set(ALL_PACKAGES)
if(USE_CONAN_boost)
  list(APPEND ALL_PACKAGES boost/1.71.0)
endif()
if(USE_CONAN_json)
  list(APPEND ALL_PACKAGES nlohmann_json/3.7.3)
endif()

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.15/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
  PROFILE ${CONAN_PROFILE}
  SETTINGS build_type=${CMAKE_BUILD_TYPE}
  REQUIRES ${ALL_PACKAGES}
  OPTIONS ${CONAN_OPTIONS_LIST}
  GENERATORS cmake virtualrunenv
  CONAN_COMMAND ${CONAN})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_define_targets()
