# CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(test_xlog)
include_directories("../xlog/")
# 指定库查找路径
link_directories("../xlog/build")
add_executable(test_xlog test_xlog.cpp)

# 指定加载的库
target_link_libraries(test_xlog xlog)




