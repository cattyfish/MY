//
//  16-Power.cpp
//  Algorithm
//
//  Created by MY on 2019/12/3.
//  Copyright © 2019 mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

double power(double base,int expolent)//没有考虑指数为负数和对0求倒数的情况
{
    double result=base;
    for(int i=1;i<expolent;i++)
    {
        result*=base;
    }
    return result;
}

bool equal(double num1,double num2)
{
    if((num1-num2)<1e-6 && (num2-num1)<1e-6)
        return true;
    return false;
}

double power2(double base,int expolent)
{
    if(equal(base,0.0) && expolent<0)
    {
        return 0.0;
    }
    
    unsigned int absExpolent=(unsigned int)(expolent);
    if(expolent<0)
        absExpolent=(unsigned int)(-expolent);
    
    if(expolent==0)
        return 1;
    double result=base;
    for(int i=1;i<absExpolent;i++)
    {
        result*=base;
    }
    if(expolent<0)
        result=1.0/result;
    return result;
        
}

int main(int argc,char * argv[])
{
    cout<<power2(0, -4)<<endl;
    return 0;
}
