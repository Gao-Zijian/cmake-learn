cmake_minimum_required(VERSION 3.20)
project(auto_search_h)

set(INCLUDE_PATH "./include")
include_directories(${INCLUDE_PATH})

# 寻找当前路径(.)的所有源码文件(*.c,*.cpp等，不含*.h)，保存到M_SRC中
aux_source_directory("." M_SRC)
aux_source_directory("./src" SRC)

# 读取所有头文件
file(GLOB H_FILE "${INCLUDE_PATH}/*.h*")
add_executable(${PROJECT_NAME} ${M_SRC} ${SRC} ${H_FILE})