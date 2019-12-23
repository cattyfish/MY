//
//  18-1DeleteNodeInList.cpp
//  Algorithm
//
//  Created by 毛煜 on 2019/12/10.
//  Copyright © 2019 mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int value):m_nValue(value),m_pNext(nullptr){}
};

void deleteNode(ListNode ** base,ListNode * deleNode)
{
    if(!base || !deleNode)
        return;
    if(deleNode->m_pNext!=nullptr)//要删除的节点不是尾节点
    {
        ListNode* pNext=deleNode->m_pNext;
        deleNode->m_nValue=pNext->m_nValue;
        deleNode->m_pNext=pNext->m_pNext;
        
        delete pNext;
        pNext=nullptr;
        
    }else if(*base==deleNode)//链表只有一个节点，要删除头节点
    {
        delete deleNode;
        deleNode=nullptr;
        *base=nullptr;
    }else//链表中有多个节点，要删除尾节点
    {
        ListNode * pNode=*base;
        while(pNode->m_pNext!=deleNode)
        {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=nullptr;
        delete deleNode;
        deleNode=nullptr;
    }
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
    
//    delete pNode4;
//    pNode4=nullptr;
    

    ListNode * head=pNode1;
    deleteNode(&head,pNode6);
    while(head!=nullptr)
    {
        cout<<head->m_nValue<<" ";
        head=head->m_pNext;
    }
    cout<<"end"<<endl;
    return 0;
}
