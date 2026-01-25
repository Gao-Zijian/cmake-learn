#[[
	message("aszfs" "aevw" "aevw")
]]

cmake_minimum_required(VERSION 3.20) 
project(message)
message("参数1")# 测试message

# 输出 参数1参数2参数3参数4，没有空格
# message("参数1" "参数2" "参数3" "参数4")

# 后面代码都不执行
# message(FATAL_ERROR "TEST FATAL_ERROR")

#进程继续，不会生成
# message(SEND_ERROR "TEST SEND_ERROR")

# add_executable(test_message test_message.cpp)

# message(WARNING "TEST WARNING")

# NOTICE(默认)
# message(NOTICE "test NOTICE")

#添加 -- 前缀
# message(STATUS "test STATUS")

#默认不显示,添加--前缀
# message(VERBOSE "test VERBOSE")

#设置日志显示级别
# cmake -S . -B build --log-level=VERBOSE

message(DEBUG "test DEBUG")
message(TRACE "test TRACE")
message("after ERROR")

#[[
CHECK_PASS 记录检查的成功结果
CHECK_FAIL 记录不成功的结果
CHECK_START 开始记录将要执行检查的消息
]]
message(=================================)
message(CHECK_START "find xcpp")

set(CMAKE_MESSAGE_INDENT "--")
#嵌套查找
message(CHECK_START "查找xlog库")
message(CHECK_PASS "成功")
#查找库的代码
message(CHECK_FAIL "not found")


