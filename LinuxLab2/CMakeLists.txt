cmake_minimum_required(VERSION 3.15)
# Минимальная версия CMake, с которой гарантированно работает проект.

project(temperament_test LANGUAGES CXX)
# Имя проекта: temperament_test. 
# LANGUAGES CXX означает, что проект использует язык C++.

set(CMAKE_CXX_STANDARD 17)
# Устанавливаем стандарт C++17 для компиляции.

set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Требуем строго C++17 — если компилятор не поддерживает, будет ошибка.

add_library(temperament STATIC src/temperament.cpp)
# Создаём статическую библиотеку "temperament".
# STATIC — значит .a (Linux/MinGW) или .lib (MSVC).
# В библиотеку входит файл src/temperament.cpp.

target_include_directories(temperament PUBLIC include)
# Добавляем путь к заголовочным файлам (папка include).
# PUBLIC — значит что этот путь нужен и библиотеке, и всем, кто её использует.

add_executable(temperament_app src/main.cpp)
# Создаём исполняемый файл (программу) "temperament_app".
# В него входит только src/main.cpp.

target_link_libraries(temperament_app PRIVATE temperament)
# Привязываем библиотеку "temperament" к приложению.
# PRIVATE — путь include/ и зависимости НЕ наследуются дальше.