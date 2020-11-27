// 如果是C++编译器运行，就用C的方式链接里面的函数
#ifdef __cplusplus
extern "C" {
#endif

#pragma once
#include <stdio.h>
void show();

#ifdef __cplusplus
}
#endif