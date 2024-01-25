cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(
    BetterSTLSourceCodeNode
    DESCRIPTION "侯捷《STL源码剖析》书籍伴读"
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(MAIN_EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_subdirectory(${PROJECT_SOURCE_DIR}/1_STL_introduction)

add_subdirectory(${PROJECT_SOURCE_DIR}/2_STL_allocator)