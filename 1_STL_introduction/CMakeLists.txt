
get_filename_component(SUBDIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(EXECUTABLE_OUTPUT_PATH ${MAIN_EXECUTABLE_OUTPUT_PATH}/${SUBDIR_NAME})

add_executable(
    1_9_1_config3
    "1_9_1_config3.cpp"
)

add_executable(
    1_9_1_config5
    "1_9_1_config5.cpp"
)