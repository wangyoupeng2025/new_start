//
// Created by 王有鹏 on 2026/4/16.
//

#ifndef NEW_START_CREATE_TEMPLATE01_H
#define NEW_START_CREATE_TEMPLATE01_H
#include <iostream>
using namespace std;
template<typename T>
T max(T a,T b) {
    return a > b ? a : b;
}
template<typename T1, typename T2>
void print(T1 a, T2 b) {
    cout << a << ", " << b << endl;
}
// 方式1：用 auto 推导（C++14）
template<typename T1, typename T2>
auto add(T1 a, T2 b) {
    return a + b;
}

template<typename T>
class Box {
private:
    T value;
public:
    void set(T v) { value = v; }
    T get() { return value; }
};

//模版特化
template<typename T>
class Printer {
public:
    void print(T value) {
        cout << "普通: " << value << endl;
    }
};

// 特化：对 bool 类型特殊处理
template<>
class Printer<bool> {
public:
    void print(bool value) {
        cout << "布尔: " << (value ? "true" : "false") << endl;
    }
};






#endif //NEW_START_CREATE_TEMPLATE01_H