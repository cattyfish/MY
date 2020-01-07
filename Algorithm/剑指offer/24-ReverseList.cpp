//
//  24-ReverseList.cpp
//  Algorithm
//
//  Created by MY on 2020/1/6.
//  Copyright © 2020 mac. All rights reserved.
//
// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。
#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode{
    int m_nVlaue;
    ListNode * m_pNext;
    ListNode(int value):m_nVlaue(value),m_pNext(nullptr){};
};

ListNode* ReverseNode(ListNode* pHead)//递迭代反转链表，要记录当前的节点和前一个节点
{
    ListNode *pPreNode=nullptr;
    ListNode *pCurNode=pHead;
    
    ListNode *newNode=nullptr;
    while(pCurNode)
    {
        ListNode *pNext=pCurNode->m_pNext;
        if(!pNext)
            newNode=pCurNode;
        
        pCurNode->m_pNext=pPreNode;
        
        pPreNode=pCurNode;
        pCurNode=pNext;
    }
    return newNode;
}


ListNode* reverseNode(ListNode* pHead)//递归反转链表
{
    if(!pHead || !pHead->m_pNext)
        return pHead;
    ListNode * pNext=pHead->m_pNext;
    ListNode * pNewNode=reverseNode(pHead->m_pNext);
    
    pNext->m_pNext=pHead;
    pHead->m_pNext=nullptr;
    return pNewNode;
}


int main(int argc,char* argv[])
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
    ListNode*target=reverseNode(pNode1);
    cout<<target->m_nVlaue<<endl;
    return 0;
}
