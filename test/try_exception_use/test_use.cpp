#include <iostream>
#include <ostream>
#include <stdexcept>
//
// Created by 王有鹏 on 2026/4/21.
//
//异常的使用
double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}
int main() {
    try {
        double a = divide(1.0, 0.0);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}