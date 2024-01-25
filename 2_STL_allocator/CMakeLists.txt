
get_filename_component(SUBDIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(EXECUTABLE_OUTPUT_PATH ${MAIN_EXECUTABLE_OUTPUT_PATH}/${SUBDIR_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
    2_1_1_jjalloc
    "2_1_1_jjalloc.cpp"
)
