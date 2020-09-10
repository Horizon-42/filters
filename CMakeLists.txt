cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ridges)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV)
find_package(gtest)

# 添加include路径
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    /usr/local/include
    /usr/local/include/opencv4/opencv2
    /usr/local/include/opencv4
    ${GTEST_INCLUDE_DIRS}
    )
link_directories(/usr/local/lib)

aux_source_directory(./src SrcFiles) 
add_executable(${PROJECT_NAME} 
    src/ridges.cpp
    src/test.cpp)   
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${GTEST_BOTH_LIBRARIES} pthread)