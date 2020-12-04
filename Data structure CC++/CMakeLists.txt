cmake_minimum_required(VERSION 3.17)
project(Data_structure_CC__ C)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

set(CMAKE_C_STANDARD 11)

add_executable(Data_structure_CC__
        03-??3_Tree_traversals_again/03-??3_Tree_traversals_again.c
        "04-??5 Root of AVL Tree/main.c"
        "04-??6 Complete Binary Search Tree/main.c"
        "04-??7 ?????????????????/main.c"
        "05-??7 ????????/main.c"
        "05-??8 File Transfer/main.c"
        "05-??9 Huffman Codes/main.c"
        "06-?1 ????????/main.c"
        "06-?2 Saving James Bond - Easy Version/main.c"
        "06-?3 ??????/main.c")
