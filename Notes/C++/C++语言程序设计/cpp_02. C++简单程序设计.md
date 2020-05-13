---
title: cpp_02. C++简单程序设计
date: 2020-03-12
categories: Cpp
---

> 本文为清华大学郑莉老师2015年于线上开设的[C++语言程序设计基础课程](https://next.xuetangx.com/course/THU08091000247/1515741)**第二、三章**的学习笔记，对应C++语言程序设计教材上**第二章**内容。

## 1 第一个cpp程序

```cpp
// #include: 编译预处理命令：编译前把头文件内容复制到此位置
#include <iostream>
// 命名空间：避免命名冲突
using namespace std;  // 打开开 std 标准库的命名空间：std::cout => cout

const double PI = 3.1415926;  // 符号常量
// '字符常量'与"字符串常量\0"

int main() {
    int a, b, d;  //  局部变量初始化为垃圾数值，全局变量初始化为0
    a = 010lu;  // 八进制unsigned long类型
    b = 0x10ll; // 十六进制longlong类型
    double c = 3e-1f;  // 3e-1f: 使double型变成float轴
    cout << "Hello!" << endl;  // <<: 流插入运算符：将字符串插入到输出流中
    cout << "Welcome to C++!" << endl;  // endl: 行结束
    cin >> d;
    cout << a << endl << b << endl << c << endl << d << endl;
    return 0;
}
```

## 2 条件表达式

```cpp
#include <iostream>
using namespace std;
 
int main() {
    int a = 2, b =1;
    int x = a > b ? a : b;  // 条件表达式
    cout << x << endl;
    cout << sizeof(x) << endl;  // sizeof运算符
}
```

## 3 显式类型转换

`类型转换操作符<类型说明符>(表达式)`
> e.g. 
> `static_cast<int>(a)`

## 4 位运算

* 按位与 `&`
* 按位或 `|`
* 按位异或 `^`
* 取反 `～`
* 移位 `<<, >>`

##

## 5 I/O 流
* 流 —— 数据从一个对象到另一个对象的流动
* 常用的I/O流类库操纵符     
    `#include <ismanip> # I/O流控制头文件`
    * `dec`——十进制表示    
    ```cpp
    cout << dec << 0x10 << endl;
    ```
    
    * `oct`——八进制表示
    ```cpp
    cout << oct << 8 << endl;
    ```
    
    * `hex`——十六进制表示
    ```cpp
    cout << hex << 16 << endl;
    ```
    
    * `ws`——提取空白符
    * `ends`——插入空白符
    ```cpp
    string s;
    cin >> ws >> s << ends << s;
    ```
    
    * `setw(int)`——设置域宽
    * `setprecision(int)`——设置小数点位(包括小数点)
    ```cpp
    cout << 1 << setw(8)  << setprecision(3) << 3.1415 << endl;
    1    3.14
    ```
    
    ##  6 控制语句  
### 6.1 Switch 语句
    
```cpp
switch (day) {
    case 1: 
        语句1;
        break;
    case 2: 
        语句2;
        break;
        .
        .
        .
    default:
        语句n;
        break;
```
    
### 6.2 do...while 循环
    
```cpp
// 翻转数字
int main() {
    int num, sum = 0, i = 1;
    cin >> num;
    do {
        cout << (num % 10);
        num /= 10;
    } while (num);
}
```
    
### 6.3 嵌套控制语句
    
```cpp
// 输入一系列整数，统计出正整数个数i和负整数个数j,读入0则结束。
int main() {
    int num, i = 0, j = 0;
    cin >> num;
    while (num) {
        if (num % 2 == 0) {
            i++;
        } else {
            j++;
        }
        cin >> num;
    }
    cout << i << endl << j << endl;
}
```
    
### 6.4 其他控制语句
* `break`
* `continue`
* `goto`

## 7 自定义类型

```cpp
#include <iostream>
using namespace std;

// 类型别名
typedef float Area; // typeof(继承C)
using Volume = float; // using

// 枚举类型（不限作用域）
enum Weekdays {Mon=1, Tue, Wed, Thu, Fri, Sat, Sun};
enum GameResults {WIN, LOSE, TIE, CANCEL};

// auto 类型
GameResults val1 = WIN;
GameResults val2 = LOSE;
auto val3 = val1 + val2;

// decltype 类型
char c;
decltype(c) d = 3; // d:char

int main() {
    GameResults result;
    for (int i = WIN; i <= CANCEL; i++) {
        result = GameResults(i); // 将int转换为GameResults
        cout << result << endl;
        cout << (Wed == 3) << endl;
    }
    return 0;
}
```

## 8 Struct 结构体

```cpp
// 输出年月日
#include <iostream>
using namespace std;
// 构建结构体
struct MyTimeStruct{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int min;
    unsigned int sec;
};

int main() {
    MyTimeStruct my_time = {2020, 3, 15, 17, 14, 0};  // 结构体赋值
    // 调用结构体
    cout << my_time.year << "年" << my_time.month << "月" << my_time.day << "日"
    << my_time.hour << "点" << my_time.min << "分" << my_time.sec << "秒" << endl;

    return 0;
}
```