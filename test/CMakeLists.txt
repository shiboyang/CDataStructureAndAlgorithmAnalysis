cmake_minimum_required(VERSION 3.10)

project(test)

add_subdirectory("../source" "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(test_matrix test_matrix.cpp)
add_executable(test_insert_string test_insert_string.cpp)
add_executable(test_random_arithmetic test_random_arithmetic.cpp)
add_executable(test_super_integer_arithmetic test_super_integer_arithmetic.cpp)

target_link_libraries(test_matrix mylibs)
target_link_libraries(test_insert_string mylibs)
