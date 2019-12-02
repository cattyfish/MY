//
//  CuttingRope.cpp
//  Algorithm
//
//  Created by MY on 2019/12/2.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

// ====================动态规划====================
int maxProductAfterCutting_solution(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;
    
    int *products=new int[length+1];
    //子问题的最优解存储在数组products里，数组里第i个元素表示长度为i的数字剪成若干段之后各段长度乘积的最大值
    products[0]=0;
    products[1]=1;
    products[2]=2;
    products[3]=3;
    
    int max=0;
    for(int i=4;i<=length;i++)
    {
        max=0;
        for(int j=1;j<=i/2;j++)
        {
            int product=products[j]*products[i-j];
            if(product>max)
                max=product;
            
            products[i]=max;
        }
    }
    max=products[length];
    
    delete[] products;
    
    return max;
}

// ====================贪婪算法====================
int maxProductAfterCutting_solution2(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;
    
    int timesOf3=length/3;
    if(length-timesOf3*3==1)
        timesOf3-=1;
    
    int timesOf2=(length-timesOf3*3)/2;
    
    return (int)(pow(3,timesOf3))*(int)(pow(2,timesOf2));
}

int main(int argc, char* argv[])
{
    cout<<maxProductAfterCutting_solution2(50)<<endl;
    return 0;
}
