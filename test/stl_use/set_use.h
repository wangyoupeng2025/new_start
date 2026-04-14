//
// Created by 王有鹏 on 2026/4/14.
//

#ifndef NEW_START_SET_USE_H
#define NEW_START_SET_USE_H
#include <set>
#include <unordered_set>
using namespace std;
void test_set01() {
    // 1. 基本使用
    set<int> numbers;
    numbers.insert(5);
    numbers.insert(3);
    numbers.insert(8);
    numbers.insert(5);  // 重复，不会插入

    cout << "size: " << numbers.size() << endl;  // 3

    // 2. 查找
    if (numbers.find(5) != numbers.end()) {
        cout << "找到了" << endl;
    }

    // 3. 遍历（有序）
    for (int x : numbers) {
        cout << x << " ";  // 3 5 8
    }

    // 4. unordered_set（无序）
    unordered_set<int> uset;
    uset.insert(5);
    uset.insert(3);
    uset.insert(8);
}





#endif //NEW_START_SET_USE_H