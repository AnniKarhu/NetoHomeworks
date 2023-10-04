cmake_minimum_required(VERSION 3.22.0)
project(figures_project_dynlib_cmake)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FiguresDynamicLibrary SHARED figure.h  figure.cpp triangle.h  triangle.cpp quadrangle.h  quadrangle.cpp isosceles_triangle.h  isosceles_triangle.cpp equilateral_triangle.h  equilateral_triangle.cpp right_triangle.h  right_triangle.cpp parallelogram.h  parallelogram.cpp diamond.h  diamond.cpp rectangle.h  rectangle.cpp  square.h  square.cpp)
add_executable(figures_project_exe source.cpp)
target_link_libraries(figures_project_exe FiguresDynamicLibrary)



