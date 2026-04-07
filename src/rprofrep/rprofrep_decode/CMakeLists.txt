CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(rprofrep_decoder C)

FILE(GLOB COMMON_SRC "${CMAKE_SOURCE_DIR}/src/common/memory_structure/*.c")   

FILE(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

ADD_LIBRARY(${PROJECT_NAME} STATIC ${SOURCES} ${COMMON_SRC})

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src/core/include
        ${CMAKE_SOURCE_DIR}/src/ext/include
        ${CMAKE_SOURCE_DIR}/src/common/memory_structure
        ${CMAKE_SOURCE_DIR}/src/rprofrep/common/
)

TARGET_COMPILE_OPTIONS(${PROJECT_NAME} 
    PUBLIC
        -O3
        -D__HIP_PLATFORM_AMD__
)

# ---- Link to the lsgpu static library ----
IF (NOT TARGET lsgpu_core)
    MESSAGE(FATAL_ERROR "lsgpu_core target not found. Ensure the parent lsgpu CMakeLists.txt is included.")
ENDIF()
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC lsgpu_core)

ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(lua)

