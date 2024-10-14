# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(RATELProf VERSION 1.0.0)

# Set output directories for all binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(CORE_PROJECT_NAME "ratelprof_core" CACHE STRING "Project name for the core part")
# set(TOOL_PROJECT_NAME "ratelprof_tool" CACHE STRING "Project name for the tool part")
# set(PLUGIN_JSON_PROJECT_NAME "ratelprof_plugin_json" CACHE STRING "Project name for the json plugin part")
# set(PLUGIN_JSON_PROJECT_NAME "ratelprof_plugin_json" CACHE STRING "Project name for the json plugin part")
# set(PLUGIN_STDOUT_PROJECT_NAME "ratelprof_plugin_stdout" CACHE STRING "Project name for the stdout plugin part")

# Add subdirectory for the shared library
add_subdirectory(src/core)
add_subdirectory(src/plugins)
# add_subdirectory(src/tools)

