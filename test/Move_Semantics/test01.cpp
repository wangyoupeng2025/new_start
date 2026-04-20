//
// Created by 王有鹏 on 2026/4/16.
//
//移动语义的学习
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> getstring() {
    vector<string> res;
    res.push_back("Hello");
    res.push_back("World");
    return res;
}


int main() {
    vector <string> vs;
    vs=getstring();
    //传统的拷贝方法


    vector<int> vi={1,2,3,4};
    vector<int> vi2=std::move(vi);
//     std::move 的本质：
// 1. 把左值转换成右值引用（类型转换，不做实际移动）
// 2. 告诉编译器："这个对象可以被移动"
// 3. 真正的移动发生在移动构造函数/移动赋值运算符中
// 4. 移动后，源对象变成"有效但未指定"的状态（通常是空）
// 5. 源对象没有被销毁，仍然存在，只是资源被转移了
    cout<<vi.size()<<endl;
    //输出是0


}