//
//  20-NumbericStrings.cpp
//  Algorithm
//
//  Created by MY on 2019/12/26.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
#include <iostream>
#include <stdio.h>
using namespace std;

bool scanUnsignedInteger(const char ** str)
{
    const char * before=*str;
    while(**str!='\0' && **str>='0' && **str<='9')
        ++(*str);
    return *str>before;
}

bool scanInteger(const char** str)
{
    if(**str=='+' || **str=='-')
        ++(*str);
    return scanUnsignedInteger(str);
}

bool isNumberic(const char* str)
{
    if(str==nullptr)
        return false;

    bool numberic=scanInteger(&str);
    cout<<numberic<<"..1"<<endl;

    if(*str=='.')
    {
        ++str;

        numberic=scanUnsignedInteger(&str)||numberic;
    }
    cout<<numberic<<"..2"<<endl;

    if(*str=='e' || *str=='E')
    {
        ++str;

        numberic=numberic && scanInteger(&str);
    }
    cout<<numberic<<"..3   "<<*str<<endl;

    
    return numberic && (*str=='\0');

}

int main(int argc,char * argv[])
{
    char arrayTest[]="823.45e+6";
    cout<<isNumberic(arrayTest)<<endl;
    return 0;
}
