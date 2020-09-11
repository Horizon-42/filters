cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ridges)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_COMPILER "g++")


find_package(OpenCV)

enable_testing()

# 添加include路径
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    /usr/local/include
    /usr/local/include/opencv4/opencv2
    /usr/local/include/opencv4
    )
link_directories(
    /usr/local/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/build)

aux_source_directory(./src SrcFiles) 
add_library(${PROJECT_NAME} SHARED
    src/ridges.cpp)   
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# 添加测试目录
add_subdirectory(test)
