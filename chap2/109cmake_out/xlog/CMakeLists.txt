# CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(xlog)

set(BUILD_SHARED_LIBS OFF) #静态库
add_definitions(-Dxlog_STATIC) #默认值1

add_library(xlog STATIC xlog.cpp xlog.h)
