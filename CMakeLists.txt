cmake_minimum_required(VERSION 2.8)

project(ridges)
set(CMAKE_CXX_COMPILER "g++")

# 添加include路径
include_directories(
    ${PROJECT_SOURCE_DIR}
    "/usr/local/include"
    "/usr/local/include/opencv4/opencv2"
    "/usr/local/include/opencv4"
    )

add_executable(${PROJECT} )    