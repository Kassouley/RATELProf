MACRO(BUILD_PLUGIN LIBRARY_NAME DIR)
    file(GLOB COMMON_SRC "${CMAKE_SOURCE_DIR}/src/common/memory_structure/*.c")   

    file(GLOB_RECURSE SOURCES 
        "${DIR}/*.cpp" 
        "${DIR}/*.c"
    )

    ADD_LIBRARY(${LIBRARY_NAME} SHARED ${SOURCES} ${COMMON_SRC})

    target_include_directories(${LIBRARY_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/src/core/include
            ${CMAKE_SOURCE_DIR}/src/ext/include
            ${CMAKE_SOURCE_DIR}/src/common/memory_structure
    )
    
    target_compile_options(${LIBRARY_NAME} 
        PUBLIC
            -O3
            -D__HIP_PLATFORM_AMD__
    )

    message(STATUS "Created shared library: ${LIBRARY_NAME}")
ENDMACRO()

option(BUILD_PLUGIN_STDOUT  "Enable STDOUT plugin build"   OFF)
option(BUILD_PLUGIN_MSGPACK "Enable MSGPACK plugin build"  ON)


if(BUILD_PLUGIN_STDOUT)
    BUILD_PLUGIN(plugin_stdout    "${CMAKE_CURRENT_SOURCE_DIR}/src/stdout")
endif()

if(BUILD_PLUGIN_MSGPACK)
    BUILD_PLUGIN(plugin_msgpack   "${CMAKE_CURRENT_SOURCE_DIR}/src/msgpack")
endif()

