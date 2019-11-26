//
//  11-MinNumberInRotatedArray.cpp
//  Algorithm
//
//  Created by MY on 2019/11/25.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
#include <stdio.h>
#include <iostream>
using namespace std;

int MinInOrder(int * array,int index1,int index2)
{
    int min=array[index1];
    for(int i=index1;i<=index2;i++)
    {
        if(array[i]<min)
            min=array[i];
    }
    return min;
}

int Min(int * array,int length)
{
    if(array==nullptr || length<=0)
    {
        std::logic_error ex("Invalid parameters");
        throw new exception(ex);
    }
    int index1=0;
    int index2=length-1;
    int indexMid=index1;//这里首先让中位数等于index1是为了使用于1，2，3，4，5这种排序数组本身的情况，此时，第一个数就是最小的数字
    while(array[index1]>=array[index2])
    {
        // 如果index1和index2指向相邻的两个数，
        // 则index1指向第一个递增子数组的最后一个数字，
        // index2指向第二个子数组的第一个数字，也就是数组中的最小数字
        if(index2-index1==1){
            indexMid=index2;
            break;
        }
        indexMid=(index2+index1)/2;
        // 如果下标为index1、index2和indexMid指向的三个数字相等，
        // 则只能顺序查找
        if(array[index1]==array[index2] && array[indexMid]==array[index1]){
            return MinInOrder(array, index1, index2);
        }
        // 缩小查找范围
        if(array[indexMid]>=array[index1]){
            index1=indexMid;
        }else if(array[indexMid]<=array[index2]){
            index2=indexMid;
        }
    }
    return array[indexMid];
}
int main(int argc, char* argv[])
{
    int array[5]={1, 2, 3, 4, 5};
    cout<<"Min Number Is:"<<Min(array, 5)<<endl;
    return 0;
}
