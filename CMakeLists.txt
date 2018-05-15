cmake_minimum_required(VERSION 3.8)
project(Perceptron)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/DataSet.txt
        cmake-build-debug/iad2_projekt
        cmake-build-debug/iad2_projekt.cbp
        cmake-build-debug/identity1.log
        cmake-build-debug/identity1.weights
        cmake-build-debug/Makefile
        data/data1.in
        data/iris.in
        iris/processiris.sh
        project/bin/app
        project/src/Aplikacja.cpp
        project/src/Dane.cpp
        project/src/Dane.hpp
        project/src/Funkcja.cpp
        project/src/Funkcja.hpp
        project/src/Losowanie.cpp
        project/src/Losowanie.hpp
        project/src/Siec.cpp
        project/src/Siec.hpp
        project/src/Warstwa.cpp
        project/src/Warstwa.hpp
        project/Makefile
        utils/log2data.py
        utils/opissieci.py
        utils/plotmaker.sh
        utils/przebieg.py
        CMakeLists.txt
        DataSet.txt
        Fixed02.txt
        Graph.txt
        Setup.txt)

add_executable(Perceptron ${SOURCE_FILES})