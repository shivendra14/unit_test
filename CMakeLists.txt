#cd build
#cmake ..
#cmake --build . --config Release

cmake_minimum_required(VERSION 3.10.0)
project(MyProject VERSION 1.0.0)

if(MSVC)
    add_definitions(/FI"Config.hpp")
else()
    # GCC or Clang
    add_definitions(-include "Config.hpp")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/library)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binary)


add_subdirectory(lib)
add_subdirectory(plugin)
add_subdirectory(app)