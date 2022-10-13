cmake_minimum_required(VERSION 3.10)

project(Proj2 VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)


add_executable(Pro2 main.cpp ../Project3/main.cpp)

target_link_libraries(Pro2 PRIVATE
        libs
        )
target_include_directories(Pro2 PRIVATE
        lib)