get_filename_component(PLUGIN_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

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

# Add the shared library (create the target first)
add_library(${PLUGIN_NAME} SHARED ${SOURCES} ${HEADERS})

target_include_directories(${PLUGIN_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(plugins
    PRIVATE
        ${SOURCES}
)

target_include_directories(plugins
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PLUGIN_NAME} ${CORE_PROJECT_NAME})