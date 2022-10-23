cmake_minimum_required(VERSION 3.10)

project(Project4 VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Proj4 main.cpp)

add_subdirectory(libs)

target_link_libraries(Proj4 PRIVATE libs)

target_include_directories(Proj4 PRIVATE libs)

