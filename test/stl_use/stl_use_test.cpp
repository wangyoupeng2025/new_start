//
// Created by 王有鹏 on 2026/4/14.
//
//stl容器的学习
//#include "Vector_use.h"
#include "day04.h"
int main() {
    //创建学生容器
    vector<shared_ptr<Student>> sts;
    sts.push_back(make_shared<Student>("小明",13));
    sts.push_back(make_shared<Student>("小红",13));
    sts.push_back(make_shared<Student>("小华",12));
    sts.push_back(make_shared<Student>("小李",14));
    sts.push_back(make_shared<Student>("小刚",13));
    //创建成绩表
    map<shared_ptr<Student>,int> scs;
    for (auto it=sts.begin();it!=sts.end();it++) {
        scs[*it]=10;

    }

    Classroom c1(sts,scs);
    c1.printscore();





}
