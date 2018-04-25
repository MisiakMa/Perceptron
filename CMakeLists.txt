cmake_minimum_required(VERSION 3.8)
project(iad2_projekt)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        data/data1.in
        data/iris.in
        iris/processiris.sh
        project/src/Aplikacja.cpp
        project/src/Funkcja.cpp
        project/src/Funkcja.hpp
        project/src/Dane.cpp
        project/src/Dane.hpp
        project/src/Warstwa.cpp
        project/src/Warstwa.hpp
        project/src/Siec.cpp
        project/src/Siec.hpp
        project/src/Losowanie.cpp
        project/src/Losowanie.hpp
        project/Makefile
        utils/log2data.py
        utils/opissieci.py
        utils/plotmaker.sh
        utils/przebieg.py

       )

add_executable(iad2_projekt ${SOURCE_FILES})