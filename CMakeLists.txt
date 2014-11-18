cmake_minimum_required (VERSION 2.6)

project (all_programming_exercises)

set_property(GLOBAL PROPERTY USE_FOLDERS OFF)

set(CMAKE_C_COMPILER "C:\\MinGW\\bin\\gcc")
set(CMAKE_CXX_COMPILER "C:\\MinGW\\bin\\g++")

message("compiler is : ${CMAKE_CXX_COMPILER_ID}")

message (cxx Flags  ${CMAKE_CXX_FLAGS})

add_executable (2_task_1 2_task_1.cpp)
add_executable (2_task_2 2_task_2.cpp)
add_executable (2_task_3 2_task_3.cpp)
add_executable (2_task_4 2_task_4.cpp)
add_executable (2_task_5 2_task_5.cpp)
add_executable (2_task_6 2_task_6.cpp)
add_executable (2_task_7 2_task_7.cpp)
add_executable (3_task_1 3_task_1.cpp)
add_executable (3_task_2 3_task_2.cpp)
add_executable (3_task_3 3_task_3.cpp)
add_executable (3_task_4 3_task_4.cpp)
add_executable (3_task_5 3_task_5.cpp)
add_executable (3_task_6 3_task_6.cpp)
add_executable (3_task_7 3_task_7.cpp)
add_executable (4_task_1 4_task_1.cpp)
add_executable (4_task_2 4_task_2.cpp)
add_executable (4_task_3 4_task_3.cpp)
add_executable (4_task_4 4_task_4.cpp)
add_executable (4_task_5 4_task_5.cpp)
add_executable (4_task_6 4_task_6.cpp)
add_executable (4_task_7 4_task_7.cpp)
add_executable (4_task_8 4_task_8.cpp)
add_executable (4_task_9 4_task_9.cpp)
add_executable (4_task_10 4_task_10.cpp)
add_executable (5_task_1 5_task_1.cpp)
add_executable (5_task_2 5_task_2.cpp)
add_executable (5_task_3 5_task_3.cpp)
add_executable (5_task_4 5_task_4.cpp)
add_executable (5_task_5 5_task_5.cpp)
add_executable (5_task_6 5_task_6.cpp)
add_executable (5_task_7 5_task_7.cpp)
add_executable (5_task_8 5_task_8.cpp)
add_executable (5_task_9 5_task_9.cpp)
add_executable (5_task_10 5_task_10.cpp)
add_executable (6_task_1 6_task_1.cpp)
add_executable (6_task_2 6_task_2.cpp)
add_executable (6_task_3 6_task_3.cpp)
add_executable (6_task_4 6_task_4.cpp)
add_executable (6_task_5 6_task_5.cpp)
add_executable (6_task_6 6_task_6.cpp)
add_executable (6_task_7 6_task_7.cpp)
add_executable (6_task_8 6_task_8.cpp)
add_executable (6_task_9 6_task_9.cpp)
add_executable (7_task_1 7_task_1.cpp)
add_executable (7_task_2 7_task_2.cpp)
add_executable (7_task_3 7_task_3.cpp)
add_executable (7_task_4 7_task_4.cpp)
add_executable (7_task_5 7_task_5.cpp)
add_executable (7_task_6 7_task_6.cpp)
add_executable (7_task_7 7_task_7.cpp)
add_executable (7_task_8_a 7_task_8_a.cpp)
add_executable (7_task_8_b 7_task_8_b.cpp)
add_executable (7_task_9 7_task_9.cpp)
add_executable (7_task_10 7_task_10.cpp)
add_executable (8_task_1 8_task_1.cpp)
add_executable (8_task_2 8_task_2.cpp)
add_executable (8_task_3 8_task_3.cpp)
add_executable (8_task_4 8_task_4.cpp)
add_executable (8_task_5 8_task_5.cpp)
add_executable (8_task_6 8_task_6.cpp)
add_executable (8_task_7 8_task_7.cpp)

file(GLOB 9_task_1_src "9_task_1*.h" "9_task_1*.cpp")
add_executable(9_task_1 ${9_task_1_src})

add_executable (9_task_2 9_task_2.cpp)
add_executable (9_task_3_1 9_task_3_1.cpp)
add_executable (9_task_3_2 9_task_3_2.cpp)

file(GLOB 9_task_4_src "9_task_4*.h" "9_task_4*.cpp")
add_executable(9_task_4 ${9_task_4_src})

file(GLOB 10_task_1_src "10_task_1*.h" "10_task_1*.cpp")
add_executable(10_task_1 ${10_task_1_src})

file(GLOB 10_task_2_src "10_task_2*.h" "10_task_2*.cpp")
add_executable(10_task_2 ${10_task_2_src})

file(GLOB 10_task_3_src "10_task_3*.h" "10_task_3*.cpp")
add_executable(10_task_3 ${10_task_3_src})

file(GLOB 10_task_4_src "10_task_4*.h" "10_task_4*.cpp")
add_executable(10_task_4 ${10_task_4_src})

file(GLOB 10_task_5_src "10_task_5*.h" "10_task_5*.cpp")
add_executable(10_task_5 ${10_task_5_src})

file(GLOB 10_task_6_src "10_task_6*.h" "10_task_6*.cpp")
add_executable(10_task_6 ${10_task_6_src})

file(GLOB 10_task_7_src "10_task_7*.h" "10_task_7*.cpp")
add_executable(10_task_7 ${10_task_7_src})

file(GLOB 10_task_8_src "10_task_8*.h" "10_task_8*.cpp")
add_executable(10_task_8 ${10_task_8_src})

file(GLOB 11_task_1_src "11_task_1*.h" "11_task_1*.cpp")
add_executable(11_task_1 ${11_task_1_src})

file(GLOB 11_task_2_src "11_task_2*.h" "11_task_2*.cpp")
add_executable(11_task_2 ${11_task_2_src})

file(GLOB 11_task_3_src "11_task_3*.h" "11_task_3*.cpp")
add_executable(11_task_3 ${11_task_3_src})

file(GLOB 11_task_4_src "11_task_4*.h" "11_task_4*.cpp")
add_executable(11_task_4 ${11_task_4_src})

file(GLOB 11_task_5_src "11_task_5*.h" "11_task_5*.cpp")
add_executable(11_task_5 ${11_task_5_src})

file(GLOB 11_task_6_src "11_task_6*.h" "11_task_6*.cpp")
add_executable(11_task_6 ${11_task_6_src})

file(GLOB 11_task_7_src "11_task_7*.h" "11_task_7*.cpp")
add_executable(11_task_7 ${11_task_7_src})

file(GLOB 12_task_1_src "12_task_1*.h" "12_task_1*.cpp")
add_executable(12_task_1 ${12_task_1_src})

file(GLOB 12_task_2_src "12_task_2*.h" "12_task_2*.cpp")
add_executable(12_task_2 ${12_task_2_src})

file(GLOB 12_task_3_src "12_task_3*.h" "12_task_3*.cpp")
add_executable(12_task_3 ${12_task_3_src})

file(GLOB 12_task_4_src "12_task_4*.h" "12_task_4*.cpp")
add_executable(12_task_4 ${12_task_4_src})

file(GLOB 12_task_5_src "12_task_5*.h" "12_task_5*.cpp")
add_executable(12_task_5 ${12_task_5_src})

file(GLOB 12_task_6_src "12_task_6*.h" "12_task_6*.cpp")
add_executable(12_task_6 ${12_task_6_src})

file(GLOB 13_task_1_src "13_task_1*.h" "13_task_1*.cpp")
add_executable(13_task_1 ${13_task_1_src})

file(GLOB 13_task_2_src "13_task_2*.h" "13_task_2*.cpp")
add_executable(13_task_2 ${13_task_2_src})

file(GLOB 13_task_3_src "13_task_3*.h" "13_task_3*.cpp")
add_executable(13_task_3 ${13_task_3_src})

file(GLOB 13_task_4_src "13_task_4*.h" "13_task_4*.cpp")
add_executable(13_task_4 ${13_task_4_src})

file(GLOB 14_task_1_src "14_task_1*.h" "14_task_1*.cpp")
add_executable(14_task_1 ${14_task_1_src})

file(GLOB 14_task_2_src "14_task_2*.h" "14_task_2*.cpp")
add_executable(14_task_2 ${14_task_2_src})

file(GLOB 14_task_3_src "14_task_3*.h" "14_task_3*.cpp")
add_executable(14_task_3 ${14_task_3_src})

file(GLOB 14_task_4_src "14_task_4*.h" "14_task_4*.cpp")
add_executable(14_task_4 ${14_task_4_src})

file(GLOB 15_task_1_src "15_task_1*.h" "15_task_1*.cpp")
add_executable(15_task_1 ${15_task_1_src})

file(GLOB 15_task_2_src "15_task_2*.h" "15_task_2*.cpp")
add_executable(15_task_2 ${15_task_2_src})

file(GLOB 15_task_3_src "15_task_3*.h" "15_task_3*.cpp")
add_executable(15_task_3 ${15_task_3_src})

file(GLOB 15_task_4_src "15_task_4*.h" "15_task_4*.cpp")
add_executable(15_task_4 ${15_task_4_src})

add_executable (16_task_1 16_task_1_main.cpp)
add_executable (16_task_2 16_task_2_main.cpp)
add_executable (16_task_3 16_task_3_main.cpp)
add_executable (16_task_4 16_task_4_main.cpp)
add_executable (16_task_5 16_task_5_main.cpp)
add_executable (16_task_6 16_task_6_main.cpp)
add_executable (16_task_7 16_task_7_main.cpp)
add_executable (16_task_8 16_task_8_main.cpp)
add_executable (16_task_9 16_task_9_main.cpp)
add_executable (16_task_10 16_task_10_main.cpp)

add_executable (17_task_1 17_task_1_main.cpp)
add_executable (17_task_2 17_task_2_main.cpp)
add_executable (17_task_3 17_task_3_main.cpp)
add_executable (17_task_4 17_task_4_main.cpp)
add_executable (17_task_5 17_task_5_main.cpp)

file(GLOB 17_task_6_src "17_task_6*.h" "17_task_6*.cpp")
add_executable(17_task_6 ${17_task_6_src})

add_executable (17_task_7 17_task_7_main.cpp)

file(GLOB 18_task_2_src "18_task_2*.h" "18_task_2*.cpp")
add_executable(18_task_2 ${18_task_2_src})

add_executable (18_task_4 18_task_4_main.cpp)