//
// Created by 王有鹏 on 2026/4/16.
//
//模版的使用
#include "create_template01.h"

int main() {
    Box<int> intBox;
    intBox.set(10);
    cout << intBox.get() << endl;  // 10

    Box<string> strBox;
    strBox.set("hello");
    cout << strBox.get() << endl;  // hello
}