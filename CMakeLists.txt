cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(AoCCPP
    VERSION 1.0
    DESCRIPTION "Advent of Code in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect all source files
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/2022/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/2023/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/2024/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Include/*.cpp"
)

add_executable(AoCCPP ${SOURCES})

target_include_directories(AoCCPP PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/2022"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/2023"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/2024"
)

#  Copy input files to build directory
add_custom_command(TARGET AoCCPP POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/src/2022/Input
    ${CMAKE_CURRENT_BINARY_DIR}/2022/Input
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/src/2023/Input
    ${CMAKE_CURRENT_BINARY_DIR}/2023/Input
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/src/2024/Input
    ${CMAKE_CURRENT_BINARY_DIR}/2024/Input
)