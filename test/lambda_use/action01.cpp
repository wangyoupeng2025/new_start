//
// Created by 王有鹏 on 2026/4/15.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    int sum=0;
//     for_each(v.begin(), v.end(), [](int x) {
//     cout << x << " ";
// });
    for_each(v.begin(),v.end(),[&sum](int x) {
        sum+=x;
    });
    cout<<sum<<endl;

    int a=1,b=3,c=0;
    auto func1=[=]() {
        return a+b;
    };
    func1();
    cout<<func1()<<endl;
}