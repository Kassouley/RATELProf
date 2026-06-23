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

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE -lstdc++)

TARGET_COMPILE_OPTIONS(${PROJECT_NAME} PUBLIC -O3 )

# ---- Link to the lsgpu static library ----
IF (NOT TARGET lsgpu_utils)
    MESSAGE(FATAL_ERROR "lsgpu_utils target not found. Ensure the parent lsgpu CMakeLists.txt is included.")
ENDIF()
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC lsgpu_utils)

ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(lua)

