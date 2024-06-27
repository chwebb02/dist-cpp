cmake_minimum_required(VERSION 3.10)
project(dist)
include_directories(include/)

set(CMAKE_CXX_FLAGS "-O3")

add_executable(dist src/main.cc)

# Add Libraries
add_library(lexer SHARED src/lexer.cc)
# add_library(syntaxTree SHARED src/syntaxTree.cc)

# Link dist to libraries
target_link_libraries(dist compiler)

# Tests
add_subdirectory(test/)