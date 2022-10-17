cmake_minimum_required(VERSION 3.10)
project(Project3 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(encrypt encrypt.cpp)
add_executable(decrypt decrypt.cpp)
add_executable(generateCodebook generateCodebook.cpp)

target_include_directories(encrypt PRIVATE lib)
target_include_directories(decrypt PRIVATE lib)

target_link_libraries(encrypt PRIVATE libs)
target_link_libraries(decrypt PRIVATE libs)