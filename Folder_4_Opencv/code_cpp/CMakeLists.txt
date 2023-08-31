cmake_minimum_required(VERSION 3.26)
project(code_cpp)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(code_cpp main.cpp
        preprocess.cpp
        preprocess.h
        predict.h
        predict.cpp)
target_link_libraries(code_cpp ${OpenCV_LIBS})

