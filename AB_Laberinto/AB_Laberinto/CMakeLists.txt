# Archivo CMakeLists.txt

# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(AB_Laberinto)

# Configurar la versión de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agregar los archivos fuente al proyecto
add_executable(AB_Laberinto
    main.cpp
    busqueda.cpp
    laberinto.cpp
    laberinto.h
    busqueda.h
)