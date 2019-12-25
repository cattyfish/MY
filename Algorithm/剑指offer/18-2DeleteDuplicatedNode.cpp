//
//  18-2DeleteDuplicatedNode.cpp
//  Algorithm
//
//  Created by MY on 2019/12/23.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。
#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode{
    int m_nValue;
    ListNode * m_pNext;
    ListNode(int value):m_nValue(value),m_pNext(nullptr){};
};

void DeleteDuplicateNodes(ListNode ** base)
{
    if(!*base && !base)
        return;
    
    ListNode* pPreNode=nullptr;//pPreNode变量为用来记录当前节点的前一个节点
    ListNode* pNode=*base;
    
    while(pNode)
    {
        ListNode *pNext=pNode->m_pNext;//pNext变量为当前节点要连接的笑一个不重复节点
        bool needDelete=false;
        if(pNext && pNode->m_nValue==pNext->m_nValue)
            needDelete=true;
        if(!needDelete)
        {
            pPreNode=pNode;
            pNode=pNode->m_pNext;
        }else{
            int value=pNode->m_nValue;
            ListNode * pToBeDel=pNode;//pToBeDel变量是待删除的节点
            while(pToBeDel && pToBeDel->m_nValue==value)
            {
                pNext=pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel=nullptr;

                pToBeDel=pNext;
            }
            if(pPreNode==nullptr)
                *base=pNext;
            else
                pPreNode->m_pNext=pNext;
            pNode=pNext;
            
        }
    }
  
}


int main(int argc,char * argv[])
{
    ListNode * pNode1=new ListNode(1);
    ListNode * pNode2=new ListNode(2);
    ListNode * pNode3=new ListNode(2);
    ListNode * pNode4=new ListNode(4);
    ListNode * pNode5=new ListNode(4);
    ListNode * pNode6=new ListNode(6);
    pNode1->m_pNext=pNode2;
    pNode2->m_pNext=pNode3;
    pNode3->m_pNext=pNode4;
    pNode4->m_pNext=pNode5;
    pNode5->m_pNext=pNode6;
    
    ListNode * head=pNode1;
    DeleteDuplicateNodes(&head);
    while(head!=nullptr)
    {
        cout<<head->m_nValue<<" ";
        head=head->m_pNext;
    }
    
    return 0;
}
