# THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
# YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 

# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# RATELProf 
project(RATELProf VERSION 1.0.0)

# Set output directories for all binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(CORE_PROJECT_NAME "ratelprof" CACHE STRING "RATELProf for the core part")

# Add subdirectory for the shared library
add_subdirectory(src/core)
add_subdirectory(src/plugins)
