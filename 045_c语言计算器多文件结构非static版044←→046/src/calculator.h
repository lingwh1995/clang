//使用多文件结构(模块化设计)编写计算器程序:头文件部分
//#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

//声明其他文件中的函数
extern void Calc(int a, int b, char op);
extern int Add_Int(int a, int b);
extern int Sub_Int(int a, int b);
extern int Mul_Int(int a, int b);
extern int Div_Int(int a, int b);
extern void Show(int a, int b, char op, int result);
#endif // !CALCULATOR_H

