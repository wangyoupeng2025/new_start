//
// Created by 王有鹏 on 2026/4/13.
//
//智能指针的练习

#ifndef NEW_START_TEST01_H
#define NEW_START_TEST01_H

#include <iostream>
#include <cstring>
#include <vector>
#include<memory>
using namespace std;
class Person {
private:
    char* name;
    int age;
    string phonenumber;

public:
    // 默认构造
    Person(const char* name, int age, string phonenumber) {  // 改为 const char*
        //cout << "这是Person类的构造" << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->phonenumber = phonenumber;
    }

    // 深拷贝构造
    Person(const Person& other) {
        //cout << "这是Person类的拷贝构造" << endl;
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
        //cout << "Person的析构函数" << endl;
        delete[] name;
    }
};

class Student : public Person {
private:
    string xuehao;
public:
    string getXuehao() {
        return xuehao;
    }
    //默认构造
    Student(const char* name, int age, string phonenumber, string xuehao)
        : Person(name, age, phonenumber){
        //cout<<"这是学生类的构造"<<endl;
        this->xuehao = xuehao;

    }
    //深拷贝构造
    Student(const Student& other)
        :Person(other){
        //cout<<"这是学生类的拷贝构造"<<endl;
        this->xuehao = other.xuehao;

    }
    void getSatus() override {
        cout << "student的状态是上学" << endl;
    }

    void getShenfen() override {
        cout << "student的身份是学生" << endl;
    }
    ~Student() {
        //cout<<"这是学生的析构"<<endl;
    }
    Student& operator=(const Student& other){
        if (this != &other) {
            Person::operator=(other);
            this->xuehao = other.xuehao;

        }
        return *this;
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
        //cout << "这是Teacher类的构造" << endl;
        this->Gonghao = Gonghao;  // ← 改这里
    }

    // 拷贝构造
    Teacher(const Teacher& other)
        : Person(other) {
        //cout << "这是Teacher类的拷贝构造" << endl;
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
        //cout << "Teacher的析构函数" << endl;
    }
};

class Classroom {
public:
    shared_ptr<Teacher> t1;
    vector<unique_ptr<Student>> vs;

    Classroom(shared_ptr<Teacher> tt, vector<unique_ptr<Student>> vv)
        : t1(tt), vs(std::move(vv)) {
        cout << "Classroom构造完成" << endl;
    }

    void printStudent() {
        cout << "\n=== 学生列表 ===" << endl;
        for (const auto& s : vs) {
            cout << "学生姓名: " << s->getName()
                 << " 年龄: " << s->getAge()
                 << " 手机号: " << s->getPhonenumber()
                 << " 学号: " << s->getXuehao() << endl;
        }
    }

    void printTeacher() {
        cout << "\n=== 老师信息 ===" << endl;
        cout << "老师姓名: " << t1->getName()
             << " 年龄: " << t1->getAge()
             << " 手机号: " << t1->getPhonenumber()
             << " 工号: " << t1->getGonghao() << endl;
    }

    ~Classroom() {
        cout << "Classroom析构" << endl;
    }
};


class Watcher {
private:
    weak_ptr<Classroom> wc;  // 弱引用，不增加引用计数

public:
    // 构造函数：接收 weak_ptr
    Watcher(weak_ptr<Classroom> w) : wc(w) {
        cout << "Watcher创建" << endl;
    }

    // 查看班级信息（需要先 lock() 获取 shared_ptr）
    void watch() {
        if (auto classroom = wc.lock()) {  // 尝试获取 shared_ptr
            cout << "\n=== 监视者查看班级信息 ===" << endl;
            classroom->printTeacher();
            classroom->printStudent();
        } else {
            cout << "班级已被销毁，无法查看" << endl;
        }
    }

    // 检查班级是否还存在
    bool isClassroomAlive() {
        return !wc.expired();
    }
};








#endif //NEW_START_TEST01_H