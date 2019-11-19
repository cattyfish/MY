//
//  03-2FindDuplicationNoEdit.cpp
//  Algorithm
//
//  Created by MY on 2019/11/19.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。#include <stdio.h>
#include <iostream>
using namespace std;
int countRange(const int * array,int length,int begin,int end)
{
    if(begin<0 || end>=length)
        return 0;
    int count=0;
    for(int i=0;i<length;i++)
    {
        if(array[i]>=begin && array[i]<=end)
            count++;
    }
    
    return count;
}
int getDuplication(const int * array,int length)
{
    if(array==nullptr || length<=0)
        return 0;
    int start=1,end=length-1;//注意，这里的start和end是题目里面的数字范围，不是数组的索引,所以start是1
    
    while(start<=end)
    {
        int middle=(end-start)/2+start;
        int count=countRange(array, length, start, middle);
        if(start==end)
        {
            if(count>1){
                return start;
            }else{
                return -1;
            }
        }
        if(count>(middle-start)+1)
        {
            end=middle;
        }else{
            start=middle+1;
        }
        
    }
    return -1;
}

int main03_2(int argc,char * argv[])
{
    int array[]={1, 7, 3, 4, 5, 6, 8, 2, 8};
    cout<<getDuplication(array, sizeof(array)/sizeof(int))<<endl;
    return 0;
}
