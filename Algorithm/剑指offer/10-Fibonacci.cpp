//
//  10-Fibonacci.cpp
//  Algorithm
//
//  Created by MY on 2019/11/25.
//  Copyright © 2019 mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

long long GetFibonacci(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    return GetFibonacci(n-1)+GetFibonacci(n-2);
}

long long GetFibonacci2(int n)
{
    int result[2]={0,1};
    if(n<2)
        return result[n];
    long long fibNMinusOne=1;
    long long fibNMinusTwo=0;
    long long fibN=0;
    for(int i=2;i<=n;i++)
    {
        fibN=fibNMinusOne+fibNMinusTwo;
        fibNMinusTwo=fibNMinusOne;
        fibNMinusOne=fibN;
    }
    return fibN;
}

int main(int argc,char * argv[])
{
    cout<<GetFibonacci2(45)<<endl;
    return 0;
}
