cmake_minimum_required(VERSION 3.10)
project(Project3 VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(encrypt encrypt2.cpp)
add_executable(decrypt decrypt2.cpp)

add_library(lib STATIC lib.cpp)
target_link_libraries(decrypt PRIVATE lib)
target_link_libraries(encrypt PRIVATE lib)