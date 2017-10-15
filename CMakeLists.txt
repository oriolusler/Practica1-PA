cmake_minimum_required(VERSION 3.8)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/Dibuix.h include/Elipse.h include/FiguraGeometrica.h include/Rectangle.h src/Dibuix.cpp src/Elipse.cpp src/FiguraGeometrica.cpp src/Rectangle.cpp)
add_executable(untitled2 ${SOURCE_FILES})