cmake_minimum_required(VERSION 3.20)
project(cmake_if)

#非0常量为真
if(1)
	message("111")
endif()

# 0为假
if(0)
	message("000")
else()
	message("0 is false")
endif()

# 假
if(OFF)
	message("OFF")
# 假
elseif(NO)
	message("NO")
else()
	message("OFF NO is false")
endif()

#空值为假
if()
	message(empty)
endif()

# -1是真
if(-1)
	message(-1是真)
endif()

#空字符串为假
if("")
	message("333")
endif()

if(-NOTFOUND)
	message("-NOTFOUND")
else()
	message("-NOTFOUND为假")
endif()

#未定义变量为假
if(VAR_NOTDEF)
	message(VAR_NOTDEF)
else()
	message(VAR_NOTDEF为假)
endif()

set(VAR_NOTDEF TRUE)
if(VAR_NOTDEF)
	message(VAR_NOTDEF)
else()
	message(VAR_NOTDEF为假)
endif()

# 非空字符串不是真的均为false
if("Y")
	message(真)
else()
	message(假)
endif()

if(NOT FALSE AND TRUE)
	message(true)	
endif()


if(DEFINED NOTDEF)
	message("DEFINED NOTDEF")
endif()


# 正则表达式匹配
if("abcd1234" MATCHES "[a-z]+")
	message(YES)
else()
	message(NO)
endif()





