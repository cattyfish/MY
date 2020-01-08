//
//  25-MergeSortedLists.cpp
//  Algorithm
//
//  Created by MY on 2020/1/7.
//  Copyright © 2020 mac. All rights reserved.
//
// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。
#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode{
    int m_nVlaue;
    ListNode * m_pNext;
    ListNode(int value):m_nVlaue(value),m_pNext(nullptr){};
};

ListNode* MergeSortedLists(ListNode* pNode1,ListNode* pNode2)//递归
{
    if(!pNode1)
        return pNode2;
    else if(!pNode2)
        return pNode1;
    
    ListNode *MergeNode=nullptr;
    if(pNode1->m_nVlaue>pNode2->m_nVlaue)
    {
        MergeNode=pNode2;
        MergeNode->m_pNext=MergeSortedLists(pNode1, pNode2->m_pNext);
    }else{
        MergeNode=pNode1;
        MergeNode->m_pNext=MergeSortedLists(pNode1->m_pNext, pNode2);
    }
    return MergeNode;
}


ListNode* MergeNodes(ListNode *pNode1,ListNode* pNode2)//迭代
{
    if(!pNode1)
        return pNode2;
    else if(!pNode2)
        return pNode1;

    ListNode* newNode=new ListNode(0);
    ListNode* tail=newNode;
    while(pNode1 && pNode2)
    {
        if(pNode1->m_nVlaue<pNode2->m_nVlaue)
        {
            tail->m_pNext=pNode1;
            pNode1=pNode1->m_pNext;
        }else{
            tail->m_pNext=pNode2;
            pNode2=pNode2->m_pNext;

        }
        tail=tail->m_pNext;
    }
    while(pNode1){
        tail->m_pNext=pNode1;
        pNode1=pNode1->m_pNext;
    }
    while(pNode2){
        tail->m_pNext=pNode2;
        pNode2=pNode2->m_pNext;
    }
    return newNode->m_pNext;
}


int main(int argc,char* argv[])
{
    ListNode * pNode1=new ListNode(1);
    ListNode * pNode2=new ListNode(2);
    ListNode * pNode3=new ListNode(3);
    ListNode * pNode4=new ListNode(4);
    ListNode * pNode5=new ListNode(5);
    ListNode * pNode6=new ListNode(6);
    ListNode * pNode7=new ListNode(7);
    ListNode * pNode8=new ListNode(8);
    
    pNode1->m_pNext=pNode3;
    pNode3->m_pNext=pNode5;
    pNode5->m_pNext=pNode7;
    
    pNode2->m_pNext=pNode4;
    pNode4->m_pNext=pNode6;
    pNode6->m_pNext=pNode8;
    
    ListNode*target=MergeNodes(pNode1, pNode2);
    while(target)
    {
        cout<<target->m_nVlaue<<" ";
        target=target->m_pNext;
    }
    return 0;
}
