# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and type (shared library)
project(${TOOL_PROJECT_NAME} VERSION 1.0.0 LANGUAGES C CXX)

# Set the output library name
set(LIBRARY_NAME ${TOOL_PROJECT_NAME})

# Find all source files in the current directory (both .c and .cpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

# Add the shared library (create the target first)
add_library(${LIBRARY_NAME} SHARED ${SOURCES})

target_link_libraries(${LIBRARY_NAME} ${CORE_PROJECT_NAME})
target_link_libraries(${LIBRARY_NAME} ${EXT_PROJECT_NAME})
