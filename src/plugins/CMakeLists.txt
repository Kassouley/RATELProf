cmake_minimum_required(VERSION 3.10)

project(plugin_lib)


MACRO(SUBDIRLIST result curdir)
    file(GLOB_RECURSE ALL_ITEMS LIST_DIRECTORIES true ${curdir} ${curdir}/*)
    set(SUBDIRS [])
    foreach(ITEM ${ALL_ITEMS})
        if(IS_DIRECTORY ${ITEM})
            list(APPEND SUBDIRS ${ITEM})
        endif()
    endforeach()
    set(${result} ${SUBDIRS})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

file(GLOB SOURCES2 "${CMAKE_SOURCE_DIR}/src/common/memory_structure/*.c")

# Now you have only directories in SUBDIRS
foreach(SUBDIR ${SUBDIRS})
    file(GLOB_RECURSE SOURCES 
        "${SUBDIR}/*.cpp" 
        "${SUBDIR}/*.c"
    )

    if (SOURCES)
        get_filename_component(BASENAME ${SUBDIR} NAME)
        set(LIBRARY_NAME "plugin_${BASENAME}")

        add_library(${LIBRARY_NAME} SHARED ${SOURCES} ${SOURCES2})

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
    endif()
endforeach()
