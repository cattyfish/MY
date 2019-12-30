//
//  21-ReorderArray.cpp
//  Algorithm
//
//  Created by MY on 2019/12/30.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <stdio.h>
#include <iostream>
using namespace std;

bool isEven(int n)
{
    return (n&0x1)==0;
}

void ReorderArray(int * pData,unsigned int length,bool (*func)(int))//双指针
{
    if(!pData || length==0)
        return;
    int * pBegin=pData;
    int * pEnd=pData+length-1;
    while(pEnd>pBegin)
    {
        while(!func(*pBegin)){
            pBegin++;
        }
        while(func(*pEnd)){
            pEnd--;
        }
        if(pEnd>pBegin){
            int temp=*pBegin;
            *pBegin=*pEnd;
            *pEnd=temp;
        }
    }
}

int main(int argc,char* argv[])
{
    int numbers[]={2, 4, 6, 1, 3, 5, 7};
    int length=sizeof(numbers)/sizeof(int);
    for(int i=0;i<length;i++)
        cout<<numbers[i]<<" ";
    cout<<endl;
    ReorderArray(numbers, length,isEven);
    for(int i=0;i<length;i++)
        cout<<numbers[i]<<" ";
    cout<<endl;
    return 0;
}
