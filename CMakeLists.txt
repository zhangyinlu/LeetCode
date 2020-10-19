# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)


project("LeetCode")

# 包含子项目。
add_subdirectory("strings")
add_subdirectory("tree")
add_subdirectory("backtracking")
