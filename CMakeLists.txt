cmake_minimum_required(VERSION 3.14)
project(Pila)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pila
        Clase_Pila.cpp
        Clase_Pila.h
        Principal_clase_pila.cpp)
