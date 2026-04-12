cmake_minimum_required(VERSION 4.0)
project(new_start)

set(CMAKE_CXX_STANDARD 20)

add_executable(new_start main.cpp
        test/helloC++.cpp
        test/class_use/class_use01.h
        test/class_use/class_day01.cpp
        test/Inheritance_use/Inheritance_test.cpp
        test/Inheritance_use/test01.h
        test/Inheritance_use/test02.h
        test/Inheritance_use/day02.h)
