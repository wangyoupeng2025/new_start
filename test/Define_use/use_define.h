//
// Created by 王有鹏 on 2026/4/20.
//

#ifndef NEW_START_USE_DEFINE_H
#define NEW_START_USE_DEFINE_H
#define DEBUG 0
//#define MACOS
//#define CLION

//上面的的宏定义语句可以防止头文件被多次包含
#define PI 3.14
//直接进行文本替换
#define SUM(x,y)\
    ((x)+(y))
//宏定义用来代替一些小函数

//宏定义中有多条代码用do while的形式
#define SWAP(a, b) do { \
typeof(a) _tmp = (a); \
(a) = (b); \
(b) = _tmp; \
} while(0)







#endif //NEW_START_USE_DEFINE_H