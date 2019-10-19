cmake_minimum_required(VERSION 3.15)
project(stl_slicer)

set(CMAKE_CXX_STANDARD 17)

add_executable(stl_slicer main.cpp Source/Model.cpp Header/Model.h++ Source/Triangle.cpp Header/Triangle.h++ Source/Coordinate.cpp Header/Coordinate.h++ Source/ModelLoader.cpp Header/ModelLoader.h++ Source/Slicer.cpp Header/Slicer.h++ Source/Point.cpp Header/Point.h++ Source/Point3.cpp Header/Point3.h++ Source/Line.cpp Header/Line.h++ Source/Exporter.cpp Header/Exporter.h++)