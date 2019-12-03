//
//  15_NumberOf1InBinary.cpp
//  Algorithm
//
//  Created by MY on 2019/12/2.
//  Copyright © 2019 mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int NumberOf1_Solution1(int n)
{
    int count=0;
    unsigned int flag=1;//单拿一个变量来进行左移操作，用这个变量去和n做与操作，如果用n做右移操作会出现负数问题
    
    while(flag<=n)
    {
        if(n&flag)
            count++;
        flag=flag<<1;
    }
    return count;
}

//把一个数减去1，再和原整数做与运算，会把该整数最右边的1变为0，
//所以一个整数的二进制中有多少个1，就进行多少次这种操作
int NumberOf1_Solution2(int n)
{
    int count=0;
    while(n)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}

int main(int argc,char * argv[])
{
    cout<<NumberOf1_Solution2(10)<<endl;
    return 0;
}
