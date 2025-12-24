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
            ${CMAKE_SOURCE_DIR}/src/rprofrep/common/
    )
    
    target_compile_options(${LIBRARY_NAME} 
        PUBLIC
            -O3
            -D__HIP_PLATFORM_AMD__
    )

    # ---- Link to the lsgpu static library ----
    if (NOT TARGET lsgpu_core)
        message(FATAL_ERROR "lsgpu_core target not found. Ensure the parent lsgpu CMakeLists.txt is included.")
    endif()
    target_link_libraries(${LIBRARY_NAME} PRIVATE lsgpu_core)

    

    message(STATUS "Created shared library: ${LIBRARY_NAME}")
ENDMACRO()


BUILD_PLUGIN(plugin_rprofrep    "${CMAKE_CURRENT_SOURCE_DIR}/src")


