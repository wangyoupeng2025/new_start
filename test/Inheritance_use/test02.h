//
// Created by 王有鹏 on 2026/4/12.
//

#ifndef NEW_START_TEST02_H
#define NEW_START_TEST02_H

#endif //NEW_START_TEST02_H
#include <iostream>
#include <string>
using namespace std;
class Base {
    public:
    virtual double getArea()=0;
    virtual  double getZhouchang()=0;
};
class Yuan : public Base {
    public:
    double r;
    Yuan(double r) : r(r) {};
    double getArea() {
        return r * r * 3.14;
    }
    double getZhouchang() {
        return r * 3.14 * 2;
    }
};