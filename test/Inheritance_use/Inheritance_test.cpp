//
// Created by 王有鹏 on 2026/4/12.
// 本次是继承、多态、虚函数的练习
//
//#include "test01.h"
//#include "test02.h"
#include "day02.h"
#include <vector>
using namespace std;

int main() {
    // 1. 创建5个学生（栈对象）
    vector<Student> students;
    students.push_back(Student("小明", 18, "138001", "S001"));
    students.push_back(Student("小红", 19, "138002", "S002"));
    students.push_back(Student("小刚", 17, "138003", "S003"));
    students.push_back(Student("小丽", 20, "138004", "S004"));
    students.push_back(Student("小华", 18, "138005", "S005"));

    // 2. 创建5个老师（栈对象）
    vector<Teacher> teachers;
    teachers.push_back(Teacher("王老师", 35, "139001", "T001"));
    teachers.push_back(Teacher("李老师", 40, "139002", "T002"));
    teachers.push_back(Teacher("张老师", 32, "139003", "T003"));
    teachers.push_back(Teacher("刘老师", 45, "139004", "T004"));
    teachers.push_back(Teacher("陈老师", 38, "139005", "T005"));

    // 3. 将学生和老师放入一个大容器
    vector<Person*> people;
    for (auto& s : students) people.push_back(&s);
    for (auto& t : teachers) people.push_back(&t);

    // 4. 通过大容器统一调用虚函数（多态）
    cout << "共有 " << people.size() << " 人" << endl;
    for (auto p : people) {
        p->getSatus();
        p->getShenfen();
    }

    return 0;

}