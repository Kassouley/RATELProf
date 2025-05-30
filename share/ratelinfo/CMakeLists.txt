cmake_minimum_required(VERSION 3.10)
project(ratelinfo C)

# Set the compiler
set(CMAKE_C_COMPILER gcc)

# Include directories
include_directories(/opt/rocm/include)

# Source files
set(SRC_FILES
    src/get_agent_info.c
    src/ratelinfo_agents_query.c
)

# Specify the executable target
add_executable(ratelinfo ${SRC_FILES})

# Set output directory for the executable
set_target_properties(ratelinfo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Linker flags
target_link_libraries(ratelinfo PRIVATE -lhsa-runtime64)
target_link_directories(ratelinfo PRIVATE /opt/rocm/lib)

