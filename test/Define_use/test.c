//
// Created by 王有鹏 on 2026/4/20.
//
#include "use_define.h"
#include <stdio.h>
//宏定义的使用

int main() {
//条件编译
#if   DEBUG==1
    printf("Hello World\n");
#else
    printf("Hello\n");
#endif

#if defined(MACOS) || defined(CLION)
    printf("Hello MacOS\n");
#else
//#error "cant action"//如果进入error这里就会阻止编译直接报错
//如果只是想要提醒，用warring，但是不会输出到终端上

#warning "MACOS or CLION not defined, skipping"
#endif

//这是宏定义的实际应用
//根据不同的操作系统，来选择将EXPORT替换成对应系统的关键字
#if defined(_MSC_VER)
    // Visual Studio
#define EXPORT __declspec(dllexport)
#elif defined(__GNUC__) || defined(__clang__)
    // GCC / Clang
#define EXPORT __attribute__((visibility("default")))
    //监测到时clang所以进入到这一分支
#else
#define EXPORT
#endif



    return 0;
}