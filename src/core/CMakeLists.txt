# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and type (shared library)
project(${CORE_PROJECT_NAME} VERSION 1.0.0 LANGUAGES C CXX)

# set(CMAKE_C_COMPILER  "/opt/rocm/llvm/bin/clang")
# set(CMAKE_CXX_COMPILER  "/opt/rocm/llvm/bin/clang")
set(CMAKE_C_COMPILER  "hipcc")
set(CMAKE_CXX_COMPILER  "hipcc")

# Set the output library name
set(LIBRARY_NAME ${CORE_PROJECT_NAME})

# Find all source files in the current directory (both .c and .cpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

# Find all header files in the current directory
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

# Collect unique directories containing header files
set(HEADER_DIRS "")
foreach(header ${HEADERS})
    get_filename_component(header_dir ${header} DIRECTORY)
    list(APPEND HEADER_DIRS ${header_dir})
endforeach()

# Remove duplicates from the list of directories
list(REMOVE_DUPLICATES HEADER_DIRS)

# Add the shared library (create the target first)
add_library(${LIBRARY_NAME} SHARED ${SOURCES} ${HEADERS})


# Use an environment variable for ROCm path, falling back to /opt/rocm if not set
set(ROCM_PATH $ENV{ROCM_PATH} CACHE PATH "Path to ROCm toolkit")
if (NOT ROCM_PATH)
    set(ROCM_PATH "/opt/rocm")
endif()

# Add include directories for ROCm and project headers
target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${ROCM_PATH}/include
        ${ROCM_PATH}/include/hip
        ${ROCM_PATH}/include/hsa
        ${HEADER_DIRS}
)

# Add compilation options to a specific target (library or executable)
target_compile_options(${LIBRARY_NAME} 
    PUBLIC
    	-D_GNU_SOURCE
        -D__HIP_PLATFORM_AMD__
)

target_include_directories(${LIBRARY_NAME} PUBLIC .)


# Install the library
install(TARGETS ${LIBRARY_NAME} DESTINATION ${CORE_PROJECT_NAME}/lib)
