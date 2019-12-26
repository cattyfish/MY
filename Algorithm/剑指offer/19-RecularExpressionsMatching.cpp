//
//  19-RecularExpressionsMatching.cpp
//  Algorithm
//
//  Created by MY on 2019/12/26.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
#include <stdio.h>
#include <iostream>
using namespace std;
bool matchCore(const char * str,const char * pattern)//主要用到了地柜的思想
{
    if(*str=='\0' && *pattern=='\0')
        return true;
    
    if(*str!='\0' && *pattern=='\0')
        return false;
    
    if(*(pattern+1)=='*')//首先对符号*就行判断，如果对.先就行判断，会出现match("abbbbbbbbbbbbbbbbbbb", "ab*")判断为错误的情况
    {
        if(*pattern==*str || (*pattern=='.' && *str!='\0'))
            return matchCore(str+1, pattern+2)//针对match("a a a", "a a* a")的情况，也就是*前的字符只出现一次
            ||matchCore(str+1, pattern)//针对match("a aaaaaa a", "a a* a")的情况，也就是*前的字符只出现一次以上
            ||matchCore(str, pattern+2);//针对match("a a", "a a* a")的情况，也就是*前的字符只出现0次
        else
            return matchCore(str, pattern+2);//针对match("aa", "ab*a")的情况，也就是*前的字符只出现0次
    }
    
    if(*str==*pattern || (*pattern=='.' && *str!='\0'))
        return matchCore(str+1, pattern+1);
    
    return false;
}

bool match(const char * str,const char * pattern)
{
    if(str==nullptr || pattern==nullptr)
        return false;
    return matchCore(str, pattern);
}

int main(int argc,char * argv[])
{
    cout<<match("aa", "a.*")<<endl;
    return 0;
}
