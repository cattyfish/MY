//
//  PrintListInReversedOrder.cpp
//  Algorithm
//
//  Created by MY on 2019/11/19.
//  Copyright © 2019 mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode{
    int m_nKey;
    ListNode * m_pNext;
    ListNode(int a):m_nKey(a),m_pNext(nullptr){};
};

void printReverse(ListNode * head)
{
    if(head==nullptr)
        return;
    
    printReverse(head->m_pNext);
    cout<<head->m_nKey<<" ";
}

int main(int argc,char * argv[])
{
    ListNode *node1=new ListNode(1);
    ListNode *node2=new ListNode(2);
    ListNode *node3=new ListNode(3);
    ListNode *node4=new ListNode(4);
    ListNode *node5=new ListNode(5);
    node1->m_pNext=node2;
    node2->m_pNext=node3;
    node3->m_pNext=node4;
    node4->m_pNext=node5;
    
    ListNode * head=node1;
    while(head!=nullptr)
    {
        cout<<head->m_nKey<<" ";
        head=head->m_pNext;
    }
    cout<<endl;
    ListNode * head2=node1;
    printReverse(head2);
    return 0;
}
