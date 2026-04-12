//
// Created by 王有鹏 on 2026/4/12.
//
//感受继承和多态
#ifndef NEW_START_DAY02_H
#define NEW_START_DAY02_H

#include <string>
#include <iostream>
#include <cstring>  // 添加这个头文件
using namespace std;

class Person {
private:
    char* name;
    int age;
    string phonenumber;

public:
    // 默认构造
    Person(const char* name, int age, string phonenumber) {  // 改为 const char*
        cout << "这是Person类的构造" << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->phonenumber = phonenumber;
    }

    // 深拷贝构造
    Person(const Person& other) {
        cout << "这是Person类的拷贝构造" << endl;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->age = other.age;
        this->phonenumber = other.phonenumber;
    }

    // 重载=运算符
    Person& operator=(const Person& other) {
        if (this != &other) {
            // 先释放旧内存！避免内存泄漏
            delete[] this->name;

            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->age = other.age;
            this->phonenumber = other.phonenumber;
        }
        return *this;
    }

    void setName(const char* name) {  // 改为 const char*
        delete[] this->name;  // 先释放旧的
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    char* getName() {
        return this->name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    void setPhonenumber(string phonenumber) {
        this->phonenumber = phonenumber;
    }

    string getPhonenumber() {
        return this->phonenumber;
    }

    virtual void getSatus() = 0;
    virtual void getShenfen() = 0;

    virtual ~Person() {
        cout << "Person的析构函数" << endl;
        delete[] name;
    }
};

class Student : public Person {
private:
    string Xuehao;

public:
    string getXuehao() {
        return Xuehao;
    }
    // 构造函数 - 必须调用父类构造！
    Student(const char* name, int age, string phonenumber, string Xuehao)
        : Person(name, age, phonenumber) {  // ✅ 关键：调用父类构造
        cout << "这是student类的构造" << endl;
        this->Xuehao = Xuehao;
    }

    // 拷贝构造 - 必须调用父类拷贝构造！
    Student(const Student& other)
        : Person(other) {  // ✅ 关键：调用父类拷贝构造
        cout << "这是student类的拷贝构造" << endl;
        this->Xuehao = other.Xuehao;
    }

    // 重载=运算符
    Student& operator=(const Student& other) {  // ✅ 加上 const
        if (this != &other) {
            Person::operator=(other);  // 调用父类赋值运算符
            this->Xuehao = other.Xuehao;
        }
        return *this;
    }

    // ✅ override 语法正确
    void getSatus() override {
        cout << "student的状态是上学" << endl;
    }

    void getShenfen() override {
        cout << "student的身份是学生" << endl;
    }

    ~Student() {
        cout << "Student的析构函数" << endl;
        // 不需要手动释放 name，父类析构会处理
    }
};

class Teacher : public Person {
private:
    string Gonghao;  // 工号

public:
    string getGonghao() {
        return Gonghao;
    }
    // 构造函数 - 参数名要和成员变量对应
    Teacher(const char* name, int age, string phonenumber, string Gonghao)  // ← 改这里
        : Person(name, age, phonenumber) {
        cout << "这是Teacher类的构造" << endl;
        this->Gonghao = Gonghao;  // ← 改这里
    }

    // 拷贝构造
    Teacher(const Teacher& other)
        : Person(other) {
        cout << "这是Teacher类的拷贝构造" << endl;
        this->Gonghao = other.Gonghao;  // ← 改这里
    }

    // 赋值运算符
    Teacher& operator=(const Teacher& other) {
        if (this != &other) {
            Person::operator=(other);
            this->Gonghao = other.Gonghao;  // ← 改这里
        }
        return *this;
    }

    void getSatus() override {
        cout << "Teacher的状态是教学" << endl;
    }

    void getShenfen() override {
        cout << "Teacher的身份是老师" << endl;
    }

    ~Teacher() {
        cout << "Teacher的析构函数" << endl;
    }
};






#endif //NEW_START_DAY02_H