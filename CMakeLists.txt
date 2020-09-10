cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ridges)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 添加include路径
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    "/usr/local/include"
    "/usr/local/include/opencv4/opencv2"
    "/usr/local/include/opencv4"
    )
find_package(OpenCV)

aux_source_directory(./src SrcFiles) 
add_executable(${PROJECT_NAME} 
    src/ridges.cpp
    src/test.cpp)   
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})