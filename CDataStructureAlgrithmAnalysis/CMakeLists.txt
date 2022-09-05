cmake_minimum_required(VERSION 3.23)
project(CDataStructureAndAlgorithmAnalysis C)

set(CMAKE_C_STANDARD 11)

include_directories(../utils)

add_executable(CDataStructureAndAlgorithmAnalysis
#        chapter1/1.c
#        chapter1/2.c
#        chapter1/3.c
#        chapter1/main.c
#        chapter2/1.c
        chapter2/main.c
        ../source
        ../utils/common.c
        ../utils/common.h ../source/list.c ../source/include/list.h ../source/sequence_stack.c ../source/include/sequence_stack.h ../DataSrtucture/chapter2/parenthesis_matching.c)
