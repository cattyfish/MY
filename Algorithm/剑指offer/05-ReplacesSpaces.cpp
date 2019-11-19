//
//  ReplacesSpaces.cpp
//  Algorithm
//
//  Created by MY on 2019/11/12.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
#include <stdio.h>
#include <iostream>
using namespace std;
void ReplaceSpaces(char* string,int length)
{
    if(string==nullptr || length<=0)
        return;
    int totalLength=0;
    int i=0;
    int blankCount=0;
    while(string[i]!='\0')
    {
        totalLength++;
        if(string[i]==' ')
            blankCount++;
        i++;
    }
    int newLength=totalLength+blankCount*2;
    if(newLength>length)
        return;
    while(totalLength>=0 && newLength>totalLength)
    {
        if(string[totalLength]!=' ')
        {
            string[newLength--]=string[totalLength];
        }else{
            string[newLength--]='%';
            string[newLength--]='0';
            string[newLength--]='2';
        }
        totalLength--;
    }
}
int main(int argc,char* argv[])
{
    char string[100]= "  We Are Happy";
    ReplaceSpaces(string, 100);
    cout<<string<<endl;
    return 0;
}
