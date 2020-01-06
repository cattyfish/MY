//
//  23-EntryNodeInListLoop.cpp
//  Algorithm
//
//  Created by MY on 2020/1/2.
//  Copyright © 2020 mac. All rights reserved.
//
// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。
#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode{
    int m_nVlaue;
    ListNode * m_pNext;
    ListNode(int value):m_nVlaue(value),m_pNext(nullptr){};
};

ListNode* MeetingNode(ListNode * pHead)//此方法是判断链表中是否有环，采用的方法是快慢指针
{
    if(!pHead)
        return nullptr;
    
    ListNode* pSlow=pHead->m_pNext;
    if(!pSlow)
        return nullptr;
    
    ListNode* pFast=pSlow->m_pNext;
    while(pFast && pSlow)
    {
        if(pFast==pSlow)
            return pFast;
        
        pSlow=pSlow->m_pNext;
        
        
        pFast=pFast->m_pNext;
        if(pFast)
            pFast=pFast->m_pNext;
    }
    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode * pHead)//此方法是获取环中的节点数目，并且返回环的入口节点
{
    ListNode * meetingNode=MeetingNode(pHead);
    if(!meetingNode)
        return nullptr;
    
    //首先得到环中节点的数目
    int nodeInLoop=1;
    ListNode *pFast=meetingNode->m_pNext;
    ListNode *pSlow=meetingNode;
    
    while(pFast!=pSlow)
    {
        nodeInLoop++;
        pFast=pFast->m_pNext;
    }
    cout<<"环中的节点数是："<<nodeInLoop<<endl;
    
    ListNode *pAhead=pHead;
    ListNode *pBehind=pHead;
    for(int i=0;i<nodeInLoop;i++)
    {
        pAhead=pAhead->m_pNext;
    }
    while(pAhead!=pBehind)
    {
        pAhead=pAhead->m_pNext;
        pBehind=pBehind->m_pNext;
    }
    
    return pAhead;
    
}

int main(int argrc,char * argv[])
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
    
    pNode6->m_pNext=pNode1;
    
    
    ListNode* entry=EntryNodeOfLoop(pNode1);
    cout<<"环的入口节点的值是："<<entry->m_nVlaue<<endl;
    return 0;
}
