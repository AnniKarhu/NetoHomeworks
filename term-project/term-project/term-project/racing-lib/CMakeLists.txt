#библиотека
cmake_minimum_required(VERSION 3.22.0)
project(racing_dynlib)						# Название проекта
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)	#включить в библиотеку все 

file(GLOB lib-src "include/*.h" "*.cpp")
#target_include_directories(${PROJECT_NAME} PUBLIC include)
add_library(RacingDynamicLibrary SHARED ${lib-src}) 

