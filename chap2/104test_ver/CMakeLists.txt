cmake_minimum_required(VERSION 3.20)
project(test_var)

set(VAR1 测试VAR1变量的值)
message("VAR1=" ${VAR1})
message("VAR1 in str ${VAR1}")
# unset(VAR1)
message("VAR1=" ${VAR1})

set(VAR2 "VAR1")
message(VAR2=${${VAR2}})