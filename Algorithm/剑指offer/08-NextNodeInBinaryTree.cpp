//
//  NextNodeInBinaryTree.cpp
//  Algorithm
//
//  Created by MY on 2019/11/22.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
#include <stdio.h>
#include <iostream>
using namespace std;
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pParent;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode(int value):m_nValue(value),m_pParent(nullptr),m_pLeft(nullptr),m_pRight(nullptr){};
    BinaryTreeNode():m_nValue(0),m_pParent(nullptr),m_pLeft(nullptr),m_pRight(nullptr){};
};
void ConstructTreeNode(BinaryTreeNode* pParent,BinaryTreeNode* pLeft,BinaryTreeNode* pRight)
{
    if(pParent!=nullptr)
    {
        pParent->m_pLeft=pLeft;
        pParent->m_pRight=pRight;
        if(pLeft!=nullptr)
            pLeft->m_pParent=pParent;
        if(pRight!=nullptr)
            pRight->m_pParent=pParent;
    }
}
/*
 分3种情况进行判断，判断的依据是此节点的右子树
 1.当此节点有右子树，它的下一个节点是它右子树中的最左子节点
 2.当此节点无右子树，且它为父节点的左子节点，那么它的下一个节点是父节点
 3.当此节点无右子树，且它为父节点的右子节点，那么沿着指向父节点的指针向上遍历，直到找到
    一个是他父节点的左子节点，那么这个左子节点的父节点就是下一个节点
 */
BinaryTreeNode * GetNext(BinaryTreeNode * pNode)
{
    if(pNode==nullptr)
        return nullptr;
    
    BinaryTreeNode * target=nullptr;
    if(pNode->m_pRight!=nullptr)//情况1
    {
        BinaryTreeNode * temp=pNode->m_pRight;
        while(temp->m_pLeft!=nullptr)
            temp=temp->m_pLeft;
        target=temp;
    }else if(pNode->m_pParent!=nullptr){
//        if(pNode==pNode->m_pParent->m_pLeft)//情况2
//            target=pNode->m_pParent;
//        else{//情况3
//            BinaryTreeNode * temp=pNode->m_pParent;
//            while(temp->m_pParent!=nullptr)
//            {
//                if(temp==temp->m_pParent->m_pLeft)
//                {
//                    target=temp->m_pParent;
//                    break;
//                }
//                temp=temp->m_pParent;
//            }
//        }
        //下面这种写法更简便，将情况2和情况3放到了一起判断，不用加if分支进行判断
        BinaryTreeNode * pCurrent=pNode;
        BinaryTreeNode * pParent=pNode->m_pParent;
        while(pParent!=nullptr && pCurrent==pParent->m_pRight)
        {
            pCurrent=pParent;
            pParent=pCurrent->m_pParent;
        }
        target=pParent;
    }
    return target;
}
int main(int argc,char* argv[])
{
    BinaryTreeNode* pNode8 = new BinaryTreeNode(8);
    BinaryTreeNode* pNode6 = new BinaryTreeNode(6);
    BinaryTreeNode* pNode10 = new BinaryTreeNode(10);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode7 = new BinaryTreeNode(7);
    BinaryTreeNode* pNode9 = new BinaryTreeNode(9);
    BinaryTreeNode* pNode11 = new BinaryTreeNode(11);
    
    ConstructTreeNode(pNode8, pNode6, pNode10);
    ConstructTreeNode(pNode6, pNode5, pNode7);
    ConstructTreeNode(pNode10, pNode9, pNode11);
    
   
    
    BinaryTreeNode * next=GetNext(pNode8);
    
    if(next!=nullptr)
    {
        cout<<"Next Node Is "<<next->m_nValue<<endl;
    }else{
        cout<<"Next Node Is Nullptr!!"<<endl;
    }
     
    
    return 0;
}
