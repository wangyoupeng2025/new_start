//
// Created by 王有鹏 on 2026/4/15.
//
//lambda配合stl常用算法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //vector是无序容器
    vector<int> v={8,1,7,3,2,4,6,9,5};
    //升序排序
    sort(v.begin(),v.end(),[](int x,int y) {
        return x<y;
    });
    //遍历
    for_each(v.begin(),v.end(),[](int x) {
        cout << x << endl;
    });
    //按条件查找
    auto it=find_if(v.begin(),v.end(),[](int x) {
        return x>=2;
    });
    cout << *it << endl;
    //按条件计数
    auto it2=count_if(v.begin(),v.end(),[](int x) {
        return x%2==0;
    });
    cout << it2 << endl;
    //改变值
    // transform：每个元素乘以 2
    transform(v.begin(), v.end(), v.begin(), [](int x) {
        return x * 2;  // 返回新值
    });
    //
    v.erase(remove_if(v.begin(), v.end(), [](int x) {
    return x % 2 == 0;
}), v.end());



    return 0;


}