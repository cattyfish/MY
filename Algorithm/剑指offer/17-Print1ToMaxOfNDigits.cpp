//
//  17-Print1ToMaxOfNDigits.cpp
//  Algorithm
//
//  Created by MY on 2019/12/4.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。
#include <stdio.h>
#include <iostream>
using namespace std;

void PrintNum(int digit)//这种方法虽然简单，但是如果输入的n很大,求最大的n位数可能会存在溢出的问题
{
    int num=1;
    int i=0;
    while (i++<digit) {
        num*=10;
    }
    for(int i=1;i<num;i++)
    {
        cout<<i<<endl;
    }
}


// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if (!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)//如果数字全部排列完，就进行打印
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits_2(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)//先让第一个数字从0循环到1，然后分别对后面的数字进行全排列
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}


int main(int argc,char* argv[])
{
    Print1ToMaxOfNDigits_2(3);
    
    return 0;
}
