//
//  03-FindDuplication.cpp
//  Algorithm
//
//  Created by MY on 2019/11/18.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
#include <stdio.h>
#include <iostream>

using namespace std;

bool FindDuplicationNum(int * array,int length,int * number)
{
    if(array==nullptr || length<=0)
        return false;
    for(int i=0;i<length;i++)
    {
        if(array[i]<0 || array[i]>=length)
            return false;
    }
    for(int i=0;i<length;i++)
    {
        while(array[i]!=i)
        {
            if(array[i]==array[array[i]])
            {
                *number=array[i];
                return true;
            }
            int temp=array[array[i]];
            array[array[i]]=array[i];
            array[i]=temp;
        }
    }
    return false;
}

int main(int argc,char* argv[])
{
    int array[]={2, 4, 2, 1, 4};
    int number=-1;
    cout<<FindDuplicationNum(array, sizeof(array) / sizeof(int),&number)<<":"<<number<<endl;
    return 0;
}

