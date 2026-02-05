### 2. cmake常用功能

#### message

生成时显示消息

```cmake
message(日志级别 参数1 参数2 ...)
```

日志级别

- FATAL_ERROR:严重的错误，进程结束，输出到stderr

- SEND_ERROR:进程继续，但不会生成，输出到stderr

- WARNING:警告，输出到stderr

- NOTICE:默认，输出到stderr

- STATUS:添加`--`前缀，输出到stdout

- VERBOSE:默认不显示，添加`--`前缀，需要指定日志级别，输出到stdout

  - ```shell
    cmake -S . -B build --log-level=VERBOSE
    ```

- DEBUG:添加`--`前缀，需要指定日志级别

  - ```shell
    cmake -S . -B build --log-level=DEBUG
    ```

- TRACE:添加`--`前缀，需要指定日式级别

  - ```
    cmake -S . -B build --log-level=TRACE
    ```

日志级别还可以是查找状态

- CHECK_PASS 记录检查的成功结果
- CHECK_FAIL 记录不成功的结果
- CHECK_START 开始记录将要执行检查的消息

设置缩进

```cmake
set(CMAKE_MESSAGE_INDENT "--")
```

取消缩进

```cmake
set(CMAKE_MESSAGE_INDENT "")
```

#### set变量入门

set设置变量

```cmake
set(变量名 变量值 变量值 ...)
```

访问变量

```cmake
${变量名}
```

嵌套访问

```cmake
${${变量名}}
```

取消变量

```cmake
unset(变量名)
```

**BUILD_SHARED_LIBS**

- ON，生成动态库
- OFF，生成静态库(默认)

**MSVC**：生成器是否是MSVC

**WIN32**：windows平台标识

**UNIX**：类UNIX平台标识

**CMAK_SYSTEM_NAME**：系统名称

**CMAKE_COLOR_MAKEFILE**

- OFF：关闭颜色
- ON：开启颜色

**PROJECT_NAME**：项目名称

---

#### include

include()将一个cmake文件引入进来，相当于C语言include，可以多次include

```cmake
include(cmake/test_cmake.cmake)

# 将查找结果赋值给ret
include(cmake/test_cmake1.cmake OPTIONAL RESULT_VARIABLE ret)
```

若文件不存在则报错，程序继续

OPTIONAL:文件不存在继续执行不报错

若未找到，RESULT_VARIABLE为NOTFOUND，若找到，值为文件的绝对路径

#### 分步编译(Linux)

首先生成

```shell
cmake -S . -B build
cd build
```

查看可生成的目标

```shell
cmake --build . --target help
```

1. 预处理(生成.i文件)

```shell
cmake --build . --target  101first_cmake.i
```

2. 编译(生成.s文件)

```shell
cmake --build . --target 101first_cmake.s
```

3. 汇编(生成.o文件)

```shell
cmake --build . --target 101first_cmake.o
```

4. 链接(生成可执行文件)

```shell
cmake --build .
```

清理

```
cmake --build . --target clean
```

显示详细的编译过程

```shell
cmake --build build -v
```

或者

```cmake
set(CMAKE_VERBOSE_MAKEFILE on)
```

#### add_subdirectory

添加一个子目录，执行子目录的cmake

### 3.cmake语法

#### if

```cmake
if()

elseif()

elseif()

else()

endif()
```

1,ON,YES,TRUE,Y或非0数（包括浮点数）则为真

0,OFF,NO,FALSE,N,IGNORE,NOTFOUND,空字符串，或以NOTFOUND结尾，变量未定义为假

环境变量总为假

取反:NOT

与:AND

或:OR

判断语句

- EXISTS:检查文件是否存在
- COMMAND:检查命令是否存在(包括函数或宏)
- DEFINED:检查是否定义了变量
- EQUAL比较字符串或数字是否相等
- EQUAL, LESS, LESS_EQUAL, GREATER, GREATER_EQUAL:数值比较
- STREQUAL, STRLESS, STRLESS_EQUAL, STRGREATER, STRGREATER_EQUAL:字符串比较
- VERSION_EQUAL, VERSION_LESS, VERSION_LESS_EQUAL,VERSION_GREATER, VERSION_GREATER_EQUAL:版本比较
- MATCHES字符串匹配（正则表达式）

#### 缓存变量

缓存变量的作用域是全局的

普通变量各子模块之间不能访问，父模块不能访问子模块变量，子模块可以读取父模块变量

```cmake
# set(<variable> <value>... CACHE <type> <docstring> [FORCE])
set(VAR1 "CACHE VAR1 VALUE1" CACHE STRING "cache doc")
```

类型:

- STRING:字符串
- BOOL:布尔类型
- FILEPATH:文件
- PATH:文件夹
- INTERNAL:内部,cmake-gui看不到

使用option()定义选项，相当于BOOL类型

```cmake
option(OPT1 "opt1 doc" OFF)
option(OPT2 "opt2 doc" ON)
```

linux使用ccmake代替cmake-gui

```shell
cmake -S . -B build
ccmake build
```

命令行传递变量(缓存变量)

```cmake
cmake -S . -B build -D PARA1=para1
```

#### 属性

**设置属性**

```cmake
set_property(entitySpecific
  [APPEND] [APPEND_STRING]
  PROPERTY propName [value1 [value2 [...]]])
```

entitySpecific:

- GLOBAL

APPEND:追加，数组形式(分号分隔)

APPEND_STRING:追加为字符串

PROPERTY:必须写

propName:属性名

value:值

**获取属性**

```cmake
get_property(resultVar entitySpecific
  PROPERTY propName
  [DEFINED | SET | BRIEF_DOCS | FULL_DOCS])
```

resultVar:返回值，可以不定义

entitySpecific:

- GLOBAL

PROPERTY:必须写

propName:属性名

- DEFINED:属性是被定义过的吗?(define_property),如果定义过resultVar为真，否则为假
- SET:属性定义过且值‘为真吗?如果为真，resultVar为真，否则为假

- BRIEF_DOCS:获取属性的简短说明
- FULL_DOCS:获取属性的完整文档

**定义属性**

```cmake
define_property(<SCOPE> PROPERTY <name>
    [INHERITED]           # 是否继承
    [BRIEF_DOCS <docs>]   # 简要文档
    [FULL_DOCS <docs>]    # 详细文档
    [INITIALIZE_FROM_VARIABLE <var>]  # 从变量初始化
)
```

SCOPE:

- GLOBAL:全局

PROPERTY:必须写

name:属性名

BRIEF_DOCS:定义简要文档

FULL_DOCS:定义详细文档

INITIALIZE_FROM_VARIABLE:
