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

double PowerWithUnsignedExponent(double base,unsigned int expolent)
{
    double result=base;
    for(int i=1;i<expolent;i++)
    {
        result*=base;
    }

    return result;
}

//这种递归的做法可以减少做乘法的次数
double PowerWithUnsignedExponent2(double base,unsigned int expolent)
{
    if(expolent==0)
        return 1.0;
    if(expolent==1)
        return base;
    
    double result=PowerWithUnsignedExponent2(base, expolent>>1);
    result*=result;
    if((expolent&0x1)==1)//这里用指数和0x1做与运算来判断指数是不是奇数
        result*=base;
    return result;
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

        
    double result=PowerWithUnsignedExponent2(base,absExpolent);
    if(expolent<0)
        result=1.0/result;
    
    return result;
}

int main(int argc,char * argv[])
{
    cout<<power2(2, -3)<<endl;
    return 0;
}
