// 目标：
//  需求：输入花费金额，根据原有金额返回剩余金额（原有金额100）
//  所需信息：花费金额，原有金额
//  处理信息：原有金额-花费金额=剩余金额
//  输出信息：剩余金额
// 设计：
//  声明原有金额常量，花费金额、剩余金额变量
//  printf:输出系统请求，要求用户输入花费金额
//  scanf:获取用户输入的花费金额，传入变量
//  剩余金额计算表达式
//  printf:输出剩余金额

// 预处理指令-在编译器编译前将stdio.h（standard input output标准I/O头文件）中的内容输入该行所在位置
#include <stdio.h>

// 函数调用的三个部分：
// 1. 函数原型
void butler(void);

// 函数头：函数名、参数、返回类型——操作系统用来判断程序运行状态
int main(void)
// 函数体：声明+语句
{
    // 声明 AMOUNT是一个直接量(literal)，const是一个修饰符
    const int AMOUNT = 100;
    // int-关键字-语言定义的单词 price-标识符-变量、函数的名称
    int price = 0, change = 100;
    // 赋值表达式语句
    // 写程序不是描述关系，写程序是表达动作，是让计算机一步一步把事情做出来
    price = 0;
    // 表达式语句：printf-运算对象 ()-运算符
    printf("请输入花费金额：");
    scanf("%d", &price);

    // 2. 函数调用
    butler();

    // 表达式=运算符+算子
    change = AMOUNT - price;
    // printf（格式化输出函数）：把num的值内嵌在字符串中，%d占位符-标记位置和输出形式
    printf("剩余金额：%d\n", change);

    return 0;
}
// 3. 函数定义
void butler(void)
{
    printf("hello！\n");
}