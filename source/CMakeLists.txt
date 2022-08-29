add_library(mylibs STATIC sequence_stack.c)


target_include_directories(
        mylibs
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
        )