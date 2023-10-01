cmake_minimum_required(VERSION 3.22.0)
project (GreaterLeaver)

set(SOURCE_LIB leaver.h leaver.cpp)
set(SOURCE_EXE GreaterLeaver.cpp)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(LeaverDynamicLibrary SHARED ${SOURCE_LIB})
add_executable(GreaterLeaverExe ${SOURCE_EXE})
target_link_libraries(GreaterLeaverExe LeaverDynamicLibrary)