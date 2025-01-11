cmake_minimum_required(VERSION 3.10)

project(plugin_lib)

# Get all files and directories in the current source directory
file(GLOB ALL_ENTRIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

# Initialize an empty list to hold subdirectories
set(SUBDIRS)

# set(CMAKE_C_COMPILER  "/opt/rocm/llvm/bin/clang")
# set(CMAKE_CXX_COMPILER  "/opt/rocm/llvm/bin/clang")
set(CMAKE_C_COMPILER  "hipcc")
set(CMAKE_CXX_COMPILER  "hipcc")

# Loop through all entries and add only directories to SUBDIRS
foreach(ENTRY ${ALL_ENTRIES})
    if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${ENTRY}")
        list(APPEND SUBDIRS ${ENTRY})
    endif()
endforeach()

file(GLOB SOURCES2 
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" 
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    )

# Now you have only directories in SUBDIRS
foreach(SUBDIR ${SUBDIRS})
    file(GLOB_RECURSE SOURCES 
        "${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/*.cpp" 
        "${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/*.c"
    )

    if (SOURCES)
        set(LIB_NAME "plugin_${SUBDIR}")

        add_library(${LIB_NAME} SHARED ${SOURCES} ${SOURCES2})

        target_include_directories(${LIB_NAME}
            PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}
                ${CMAKE_CURRENT_SOURCE_DIR}
                ${CMAKE_CURRENT_SOURCE_DIR}/include
                ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/include
        )

        target_link_libraries(${LIB_NAME} ${CORE_PROJECT_NAME})

        message(STATUS "Created shared library: ${LIB_NAME}")
    endif()
endforeach()
