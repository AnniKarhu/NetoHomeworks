#������
cmake_minimum_required(VERSION 3.22.0)
project(racing)					# �������� �������
include_directories(racing-lib) # ������������ ������������ ������
add_subdirectory(racing-lib)  # ���������� ���������� (���������� �������������� CMakeLists.txt �� �����������), ����������� ��� ����������� -  ���������� � �����������, ������� ����� ������ ��� ���������������
#target_include_directories(${PROJECT_NAME} PUBLIC racing-lib) #���������� ����� ������ ����������, �� ������� ������� ����
#target_include_directories(${PROJECT_NAME} PUBLIC include) #���������� ����� ������ ����������, �� ������� ������� ����

file(GLOB source_files "*.h" "*.cpp")
#add_executable(${PROJECT_NAME} source.cpp) # ������� ����������� ����
add_executable(${PROJECT_NAME} ${source_files}) # ������� ����������� ����

target_link_libraries(${PROJECT_NAME} RacingDynamicLibrary) # �������� ��������� � �����������  
