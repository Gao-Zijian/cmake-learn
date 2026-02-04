cmake_minimum_required(VERSION 3.20)
project(cmake_cache)

#设置缓存变量,字符串类型
# set(VAR1 "CACHE VAR1 VALUE1" CACHE STRING "cache doc")
#缓存变量第二次修改不生效
# set(VAR1 "CACHE VAR1 VALUE2" CACHE STRING "cache doc")
message("${VAR1}")
#强制修改缓存(FORCE)
set(VAR1 "CACHE VAR1 VALUE3" CACHE STRING "cache doc" FORCE)
message("${VAR1}")


set(VAR_NORMAL "VAR_NORMAL")

message("in main")
# 普通变量子模块可以读取
add_subdirectory("sub1")
add_subdirectory("sub2")
message("VAR_NORMAL_CACHE=${VAR_NORMAL_CACHE}")

set(VAR_BOOL1 "ON" CACHE BOOL "VAR_BOOL1")
set(VAR_BOOL2 "OFF" CACHE BOOL "VAR_BOOL2")
message("VAR_BOOL1=${VAR_BOOL1}")
message("VAR_BOOL2=${VAR_BOOL2}")

set(VAR_FILE "filepath" CACHE FILEPATH "VAR_FILE")
set(VAR_PATH "path" CACHE PATH "PATH")
# 内部缓存变量
set(VAR_INTERNAL "VAR_INTERNAL" CACHE INTERNAL "VAR_INTERNAL")

option(OPT1 "opt1 doc" OFF)
option(OPT2 "opt2 doc" ON)

#命令行传递变量（缓存变量，含FORCE）
message("PARA1=${PARA1}")

message("BUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}")
message("out main")