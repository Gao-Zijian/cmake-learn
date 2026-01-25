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

