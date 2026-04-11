//
// Created by 王有鹏 on 2026/4/11.
//

#ifndef NEW_START_CLASS_USE01_H
#define NEW_START_CLASS_USE01_H
#include<string>
#include<vector>
using namespace std;
typedef enum {male, female} Sex;
ostream& operator<<(ostream& os, Sex s) {
    os << (s == male ? "男" : "女");
    return os;
}
//以上是重载运算符的使用，ostream& 代表返回的是引用输出流对象（cout就是这种类型）
// 第1步：cout << sex
//   └─ 调用 operator<<(cout, sex)
//   └─ 输出"男"
//   └─ 返回 cout（重要！）
// 第2步：现在变成 (cout) << "你好"
//   └─ cout << "你好"（这是本来就有的功能）
//   └─ 输出"你好"
//   └─ 返回 cout
// 第3步：现在变成 (cout) << endl
//   └─ cout << endl（换行）
//   └─ 返回 cout
//这样可以实现链式调用




class student {
private:
    char* name;//将name改为可变的字符指针，来体验析构函数
    int age;
    Sex sex;
    char* address;
public:
    //这是浅拷贝版本
    student(const char* n,int age,Sex sex,char* addr) {
        //this->name=name;
        name = new char[strlen(n) + 1];     // 分配内存
        strcpy(name, n);                    // 复制内容

        address = new char[strlen(addr) + 1]; // 分配内存
        strcpy(address, addr);                // 复制内容

        this->age=age;
        this->sex=sex;
        //this->address=address;
    }
//深拷贝版本
    student(const student& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        this->age = other.age;
        this->sex = other.sex;

        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);

        cout << "拷贝构造: " << name << endl;
    }
    //重载复制运算符
    student& operator=(const student& other) {
        if (this != &other) {  // 防止自赋值
            delete[] name;
            delete[] address;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            this->age = other.age;
            this->sex= other.sex;
            address = new char[strlen(other.address) + 1];
            strcpy(address, other.address);
        }
        return *this;
    }



    string getName() {
        return string(name);
    }
    int getAge() {
        return age;
    }
    Sex getSex() {
        return sex;
    }
    string getAddress() {
        return string(address);
    }

    ~student() {
        cout<<"析构函数，释放name和address的空间"<<endl;
        //析构函数delete只能释放由new开辟的空间
        delete[] name;
        delete[] address;
    }

};




#endif //NEW_START_CLASS_USE01_H