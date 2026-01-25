# 105message_color/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(message_color)
#[[
\033[1;31;40m    <!--1-高亮显示 31-前景色红色  40-背景色黑色-->
\033[0m          <!--采用终端默认设置，即取消颜色设置-->
显示方式  
0                终端默认设置
1                高亮显示
4                使用下划线
5                闪烁
7                反白显示
8                不可见

前景色            背景色           颜色
---------------------------------------
30                40              黑色
31                41              红色
32                42              绿色
33                43              黃色
34                44              蓝色
35                45              紫红色
36                46              青蓝色
37                47              白色
]]

string(ASCII 27 Esc)
set(R "${Esc}[0;31m")
set(E "${Esc}[m")
message(${R}红色${E})