cmake_minimum_required(VERSION 3.20)
project(cmake_property)

# 全局属性
set_property(GLOBAL PROPERTY TEST_GLOBAL "test global001")

get_property(val GLOBAL PROPERTY TEST_GLOBAL)

message(TEST_GLOBAL="${val}")
add_subdirectory("sub1")

# 访问子目录的全局属性

# get_property(val GLOBAL PROPERTY SUB1_GLOBAL )
message("SUB1_GLOBAL=${val}")

# APPEND APPEND_STRING
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 001")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 002")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 003")

get_property(val GLOBAL PROPERTY TEST_APPEND)


# 输出:TEST_APPEND=append 001;append 002
# 以分号间隔(数组形式)
message("TEST_APPEND=${val}")



set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append 001")
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append 002")
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append 003")

get_property(val GLOBAL PROPERTY TEST_APPEND_STRING)

#输出:TEST_APPEND_STRING=append 001append 002append 003
# 字符串形式拼接
message("TEST_APPEND_STRING=${val}")

set_property(GLOBAL PROPERTY P1 "p1")
get_property(var GLOBAL PROPERTY P1 DEFINED)
message("P1=${var}")


# BRIEF_DOCS:简短说明,可以对已有属性添加说明
define_property(GLOBAL PROPERTY TEST_DEF  BRIEF_DOCS "TEST_DEF doc")
get_property(var GLOBAL PROPERTY TEST_DEF DEFINED)
message("TEST_DEF=${var}")


get_property(var GLOBAL PROPERTY TEST_DEF BRIEF_DOCS)
message("TEST_DEF BRIEF_DOCS=${var}")

