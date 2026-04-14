//
// Created by 王有鹏 on 2026/4/14.
//

#ifndef NEW_START_VECTOR_USE_H
#define NEW_START_VECTOR_USE_H
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void test01() {
    vector<int> v;//存储的是int类型的数据
    v.reserve(100);//  提前设定最大容量
    v.push_back(10);// 添加内容
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    // 插入和删除
    v.insert(v.begin(), 0);      // 头部插入（O(n)）
    v.erase(v.begin() + 2);      // 删除第3个元素
    //for (auto& x:v) {}
    for (auto it=v.begin();it!=v.end();++it) {
        cout<<*it<<endl;

    }
}

void test02() {
    // vector<bool> 特化（注意：不是 bool 数组）
    vector<bool> flags(10, true);

    flags[0] = false;

}








#endif //NEW_START_VECTOR_USE_H