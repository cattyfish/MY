//
//  22-KthNodeFromEnd.cpp
//  Algorithm
//
//  Created by MY on 2020/1/2.
//  Copyright © 2020 mac. All rights reserved.
//
// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。
#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode{
    int m_nVlaue;
    ListNode * m_pNext;
    ListNode(int value):m_nVlaue(value),m_pNext(nullptr){};
};

ListNode *FindKthToTail(ListNode * pListHead,unsigned int k)
{
    if(!pListHead || k==0)
        return nullptr;
    
    ListNode * pAhead=pListHead;
    ListNode * pBehind=pListHead;
    
    for(unsigned int i=0;i<k-1;i++)
    {
        if(pAhead->m_pNext)
        {
            pAhead=pAhead->m_pNext;
        }else{
            return nullptr;
        }
    }
    
    while(pAhead->m_pNext)
    {
        pAhead=pAhead->m_pNext;
        pBehind=pBehind->m_pNext;
    }
    
    return pBehind;
}

int main(int argc,char * argv[])
{
    ListNode * pNode1=new ListNode(1);
    ListNode * pNode2=new ListNode(2);
    ListNode * pNode3=new ListNode(3);
    ListNode * pNode4=new ListNode(4);
    ListNode * pNode5=new ListNode(5);
    ListNode * pNode6=new ListNode(6);
    
    pNode1->m_pNext=pNode2;
    pNode2->m_pNext=pNode3;
    pNode3->m_pNext=pNode4;
    pNode4->m_pNext=pNode5;
    pNode5->m_pNext=pNode6;
    
    ListNode * target=FindKthToTail(pNode1, 4);
    cout<<target->m_nVlaue<<endl;
}
