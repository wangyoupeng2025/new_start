//
// Created by 王有鹏 on 2026/4/14.
//

#ifndef NEW_START_MAP_USE_H
#define NEW_START_MAP_USE_H
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

void test10() {
    // map：有序（红黑树），O(log n)
    // unordered_map：无序（哈希表），O(1) 平均
    map<string, int> scores;//存储的是键值对
    scores["小明"] = 100;//可用通过string字符串，来找到对应的数据
    scores["小红"] = 95;
    scores["小刚"] = 87;

    // 2. 查找（通过key来查找value）
    if (scores.find("小明") != scores.end()) {
        cout << "小明: " << scores["小明"] << endl;
    }

    // 3. 遍历（有序输出）
    for (const auto& [name, score] : scores) {
        cout << name << ": " << score << endl;
    }

    // 4. C++17 结构化绑定
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 5. try_emplace（C++17，更高效）
    scores.try_emplace("小李", 92);

    // 6. unordered_map 用法相同，只是无序
    unordered_map<string, int> umap;
    umap["小明"] = 100;

}





#endif //NEW_START_MAP_USE_H