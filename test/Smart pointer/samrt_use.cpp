//
// Created by 王有鹏 on 2026/4/13.
//
//智能指针的使用
#include "test01.h"

int main() {
    cout << "========== 创建班级1 ==========" << endl;

    // 创建学生（使用 unique_ptr）
    vector<unique_ptr<Student>> students;
    students.push_back(make_unique<Student>("小明", 10, "123456", "01"));
    students.push_back(make_unique<Student>("小王", 12, "123456", "02"));
    students.push_back(make_unique<Student>("小红", 11, "123456", "03"));
    students.push_back(make_unique<Student>("小驴", 10, "123456", "04"));
    students.push_back(make_unique<Student>("小蓝", 11, "123456", "05"));

    // 创建老师（使用 shared_ptr）
    auto teacher = make_shared<Teacher>("王老师", 25, "2244", "A1");

    // 创建班级1
    auto classroom01 = make_shared<Classroom>(teacher, std::move(students));

    cout << "\n========== 创建班级2 ==========" << endl;

    // 创建班级2（共享同一个老师）
    vector<unique_ptr<Student>> students01;
    students01.push_back(make_unique<Student>("大明", 10, "123456", "06"));
    students01.push_back(make_unique<Student>("大王", 12, "123456", "07"));
    students01.push_back(make_unique<Student>("大红", 11, "123456", "08"));
    students01.push_back(make_unique<Student>("大驴", 10, "123456", "09"));
    students01.push_back(make_unique<Student>("大蓝", 11, "123456", "10"));

    auto classroom02 = make_shared<Classroom>(teacher, std::move(students01));

    // 打印班级信息
    cout << "\n========== 班级1信息 ==========" << endl;
    classroom01->printTeacher();
    classroom01->printStudent();

    cout << "\n========== 班级2信息 ==========" << endl;
    classroom02->printTeacher();
    classroom02->printStudent();

    // ✅ 创建监视者（使用 weak_ptr 观察班级）
    cout << "\n========== 监视者测试 ==========" << endl;

    Watcher watcher01(classroom01);  // 监视班级1
    Watcher watcher02(classroom02);  // 监视班级2

    // 通过监视者查看班级信息
    watcher01.watch();
    watcher02.watch();

    // 验证引用计数
    cout << "\n老师被 " << teacher.use_count() << " 个班级共享" << endl;

    // 演示：销毁一个班级后，监视者无法查看
    cout << "\n========== 销毁班级1 ==========" << endl;
    classroom01.reset();  // 释放班级1

    cout << "\n班级1是否还存在？" << (watcher01.isClassroomAlive() ? "是" : "否") << endl;
    watcher01.watch();  // 尝试查看已销毁的班级
    watcher02.watch();  // 班级2仍然存在

    return 0;
}
