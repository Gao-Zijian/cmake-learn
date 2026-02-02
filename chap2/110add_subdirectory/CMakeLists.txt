cmake_minimum_required(VERSION 3.20)
project(xlog)
include_directories(xlog)

# CMakeLists.txt的绝对路径
message("${CMAKE_CURRENT_LIST_DIR}")

#静态库
# set(SHARED_LIBS OFF)
# add_definitions(-Dxlog_STATIC) #默认值1


# 动态库
set(BUILD_SHARED_LIBS ON)
#可执行文件的输出路径(.exe,.pdb,.dll(windows))
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

#库路径(动态库，静态库)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

#静态库输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")

add_subdirectory("xlog")
add_subdirectory("test_xlog")

# add_library(xlog xlog/xlog.cpp)
# add_executable(test_xlog test_xlog/test_xlog.cpp xlog)

# target_link_libraries(test_xlog xlog)