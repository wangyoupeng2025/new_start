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
        test/Inheritance_use/day02.h
        "test/Smart pointer/samrt_use.cpp"
        "test/Smart pointer/test01.h"
        test/stl_use/stl_use_test.cpp
        test/stl_use/Vector_use.h
        test/stl_use/map_use.h
        test/stl_use/set_use.h
        test/stl_use/list_and_deque_use.h
        test/stl_use/day04.h
        test/lambda_use/action01.cpp
        test/stl_suanfa/test_suanfa.cpp
        test/Move_Semantics/test01.cpp
        test/template_use/create_template01.h
        test/template_use/test01.cpp
        test/Define_use/use_define.h
        test/Define_use/test.c)
