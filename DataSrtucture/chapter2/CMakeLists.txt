cmake_minimum_required(VERSION 3.10.2)

project(main VERSION 1.0)

add_subdirectory("../../source" "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(Main main.c parenthesis_matching.c)

target_link_libraries(Main mylibs)

target_include_directories(Main
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )