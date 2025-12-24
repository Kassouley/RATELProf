cmake_minimum_required(VERSION 3.16)

project(rprofrep_decoder C)


file(GLOB COMMON_SRC "${CMAKE_SOURCE_DIR}/src/common/memory_structure/*.c")   

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

ADD_LIBRARY(${PROJECT_NAME} STATIC ${SOURCES} ${COMMON_SRC})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src/core/include
        ${CMAKE_SOURCE_DIR}/src/ext/include
        ${CMAKE_SOURCE_DIR}/src/common/memory_structure
        ${CMAKE_SOURCE_DIR}/src/rprofrep/common/
)

target_compile_options(${PROJECT_NAME} 
    PUBLIC
        -O3
        -D__HIP_PLATFORM_AMD__
)

# ---- Link to the lsgpu static library ----
if (NOT TARGET lsgpu_core)
    message(FATAL_ERROR "lsgpu_core target not found. Ensure the parent lsgpu CMakeLists.txt is included.")
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC lsgpu_core)

add_subdirectory(test)
add_subdirectory(lua)

