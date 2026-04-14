//
// Created by 王有鹏 on 2026/4/14.
//

#ifndef NEW_START_DAY04_H
#define NEW_START_DAY04_H
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Student {
private:
    string name;
    int age;
public:
    Student(string name, int age) : name(name), age(age) {}
    Student() {}
    Student(Student& other) {
        this->name = other.name;
        this->age = other.age;
    }
    Student& operator=(Student& other) {
        if (this == &other) {
            this->name = other.name;
            this->age = other.age;
        }
        return *this;
    }
    ~Student() {}
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setName(string name) {
        this->name = name;
    }
};
class Classroom {
    public:
    vector<shared_ptr<Student>> students;
    map<shared_ptr<Student>,int> studentscores;
    Classroom() {}
    Classroom(vector<shared_ptr<Student>> ss,
    map<shared_ptr<Student>,int> sc)
        : students(ss), studentscores(sc) {}
    void addStudent(shared_ptr<Student> ss,int score) {
        students.push_back(std::move(ss));
        studentscores[ss]=score;
    }
    void printscore() {
        for (const auto& [student, score] : studentscores) {
            cout << "学生" << student->getName() << "成绩" << score << endl;
        }
    }

};




#endif //NEW_START_DAY04_H