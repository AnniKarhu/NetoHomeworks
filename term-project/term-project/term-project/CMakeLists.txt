#проект
cmake_minimum_required(VERSION 3.22.0)
project(racing)					# Название проекта
include_directories(racing-lib) # Расположение заголовочных файлов
add_subdirectory(racing-lib)  # Добавление подпроекта (подключить дополнительный CMakeLists.txt из подкаталога), указывается имя дирректории -  директория с подпроектом, который будет собран как самостоятельный
#target_include_directories(${PROJECT_NAME} PUBLIC racing-lib) #добавление путей поиска заголовков, от которых зависит цель
#target_include_directories(${PROJECT_NAME} PUBLIC include) #добавление путей поиска заголовков, от которых зависит цель

file(GLOB source_files "*.h" "*.cpp")
#add_executable(${PROJECT_NAME} source.cpp) # Создает исполняемый файл
add_executable(${PROJECT_NAME} ${source_files}) # Создает исполняемый файл

target_link_libraries(${PROJECT_NAME} RacingDynamicLibrary) # Линковка программы с библиотекой  
