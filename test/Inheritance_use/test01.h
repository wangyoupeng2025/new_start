//
// Created by 王有鹏 on 2026/4/12.
//

#ifndef NEW_START_TEST01_H
#define NEW_START_TEST01_H

#endif //NEW_START_TEST01_H

#include<iostream>

#include<string>
using namespace std;
class Animal {
    public:
    virtual void saySomething() {
        cout<<"动物叫声"<<endl;
    }
    Animal() {
        cout<<"动物基类的构造"<<endl;
    }
    ~Animal() {
        cout<<"动物基类的析构"<<endl;
    }

};
class Dog : public Animal {
    public:
    void saySomething () {
        cout<<"狗叫声音"<<endl;
    }
    Dog() {
        cout<<"狗类的构造"<<endl;
    }
    ~Dog() {
        cout<<"狗类的析构"<<endl;
    }
};
class Cat : public Animal {
    public:
    void saySomething() {
        cout<<"猫叫声"<<endl;
    }
};