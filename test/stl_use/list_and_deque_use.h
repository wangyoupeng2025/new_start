//
// Created by 王有鹏 on 2026/4/14.
//

#ifndef NEW_START_LIST_AND_DEQUE_USE_H
#define NEW_START_LIST_AND_DEQUE_USE_H
#include <iostream>
#include <list>
#include <deque>
using namespace std;

void test_list_and_deque01() {
    // list：双向链表，中间插入/删除快
    list<int> lst;
    lst.push_back(10);
    lst.push_front(5);
    lst.insert(++lst.begin(), 7);
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    // 不支持随机访问（没有 [] 操作符）
    // auto it = lst.begin() + 2;  // ❌ 错误

    // deque：双端队列，头尾操作快
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(5);
    dq.insert(++dq.begin(), 7);
    cout << dq[1] << endl;  // 支持随机访问
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }

}





#endif //NEW_START_LIST_AND_DEQUE_USE_H