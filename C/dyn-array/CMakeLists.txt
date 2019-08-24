cmake_minimum_required(VERSION 2.6)
project(DYN_ARRAY)

set(SOURCE_FILES ./lib/dyn-array.c ./lib/dyn-array.h main.c)
add_executable(DYN_ARRAY ${SOURCE_FILES})
