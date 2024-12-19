cmake_minimum_required(VERSION 2.8.11)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Release or Debug" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall" CACHE INTERNAL "")

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

file(GLOB USER_FILES_1
"code/*.hpp"
"code/*.cpp"
)

add_executable(trie "app/main.cpp" ${USER_FILES_1})