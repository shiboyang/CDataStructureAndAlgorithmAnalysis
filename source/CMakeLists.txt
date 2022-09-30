add_library(mylibs STATIC
        sequence_stack.c
        sequence_queue.c
        link_list.c
        list.cpp
        matrix.cpp
        ../projects/Project2/main.cpp)


target_include_directories(
        mylibs
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)