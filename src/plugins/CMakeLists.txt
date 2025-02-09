cmake_minimum_required(VERSION 3.10)

project(plugin_lib)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
file(GLOB SOURCES2 
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" 
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    )

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
        )

        target_link_libraries(${LIBRARY_NAME} ${CORE_PROJECT_NAME})
        target_link_libraries(${LIBRARY_NAME} ${EXT_PROJECT_NAME})

        message(STATUS "Created shared library: ${LIBRARY_NAME}")
    endif()
endforeach()
