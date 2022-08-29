cmake_minimum_required(VERSION 3.10.2)

project(main VERSION 1.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/include")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/include")

add_subdirectory("../../source" "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(main main.c parenthesis_matching.c)

target_link_libraries(main mylibs)

target_include_directories(main
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )