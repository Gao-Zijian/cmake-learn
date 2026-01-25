cmake_minimum_required(VERSION 3.20)
project(xlog)

# 提供信息的变量

#改变行为的变量
# BUILD_SHARED_LIBS为ON:动态库，OFF:静态库（默认）
# 静态库
set(BUILD_SHARED_LIBS OFF)

add_definitions(-Dxlog_STATIC)

# 描述系统的变量
message("MSVC=" ${MSVC})
message("WIN32=" ${WIN32})
message("UNIX=" ${UNIX})
message("CMAK_SYSTEM_NAME=" ${CMAK_SYSTEM_NAME})
set(CMAKE_COLOR_MAKEFILE OFF)
add_library(${PROJECT_NAME}  xlog/xlog.cpp)
