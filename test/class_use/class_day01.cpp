//
// Created by 王有鹏 on 2026/4/11.
//
#include <iostream>
#include "class_use01.h"


int main() {
    student st1("John",12,female,"Doe");
    student st2("mike",21,male,"Doe");
    cout<<"姓名："<<st1.getName()<<"年龄："<<st1.getAge()<<"性别："<<st1.getSex()<<"地址："<<st1.getAddress()<<endl;
    cout<<"姓名："<<st2.getName()<<"年龄："<<st2.getAge()<<"性别："<<st2.getSex()<<"地址："<<st2.getAddress()<<endl;
    vector<student> vst;
    vst.reserve((2));//预分配两个空间，防止因扩容导致多调用一次student的拷贝构造函数
    vst.push_back(st1);
    vst.push_back(st2);
    for (vector<student>::iterator it=vst.begin(); it!=vst.end(); it++) {
        cout<<(*it).getName()<<'\t'
        <<(*it).getAge()<<'\t'
        <<(*it).getAddress()<<'\t'
        <<(*it).getSex()<<endl;
    }

    return 0;
}