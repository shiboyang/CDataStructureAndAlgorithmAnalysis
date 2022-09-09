cmake_minimum_required(VERSION 3.10.2)

project(main VERSION 1.0)

add_subdirectory("../../source" "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(Main2 expression_evaluation.c)

add_executable(QueueMain queue_practice.c)

add_executable(Main test.c)

target_link_libraries(Main2 mylibs m)
target_link_libraries(QueueMain mylibs m)

