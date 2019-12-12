cmake_minimum_required(VERSION 2.8)

project(AlgoFeeder)

add_definitions(-std=c++14)

include_directories(include)

SET(H include/insertionSort.h)
SET(SOURCES src/insertionSort.cpp)

SET(H1 include/AlgoFeeder.h)
SET(H2 include/gnuplot.h)

add_library(AlgoFeeder ${SOURCES} ${H} ${H1} ${H2})
add_executable(insertionSort.out src/insertionSort.cpp)
target_link_libraries(insertionSort.out ${${PROJECT_NAME}_EXPORTED_TARGETS})
