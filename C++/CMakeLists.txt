cmake_minimum_required(VERSION 3.22)
project(lists)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(LIST_DIRECTORY lists)

set(SOURCES_LIST
        ${LIST_DIRECTORY}/doubly-linked-list.hpp
        ${LIST_DIRECTORY}/head-tail-linked-list.hpp
        ${LIST_DIRECTORY}/linked-list.hpp
        ${LIST_DIRECTORY}/list.hpp
        ${LIST_DIRECTORY}/static-linked-list.hpp
        ${LIST_DIRECTORY}/static-list.hpp
        ${LIST_DIRECTORY}/list.cpp)

add_executable(dsa main.cpp ${SOURCES_LIST})

target_include_directories (dsa PRIVATE ${SOURCES_LIST})