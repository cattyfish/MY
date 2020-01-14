//
//  26-SubstructureInTree.cpp
//  Algorithm
//
//  Created by MY on 2020/1/8.
//  Copyright © 2020 mac. All rights reserved.
//
// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。
#include <stdio.h>
#include <iostream>
using namespace std;

struct BinaryTreeNode{
    double m_dbValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_dbValue = dbValue;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot)
    {
        BinaryTreeNode * pLeft=pRoot->m_pLeft;
        BinaryTreeNode * pRight=pRoot->m_pRight;
        
        delete pRoot;
        pRoot=nullptr;
        
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

bool Equal(double num1,double num2)
{
    if(num1-num2<1e-6 && num2-num1<1e-6)
        return true;
    return false;
}

bool DoesTree1HasTree2(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2)
{
    if(!pRoot2)
        return true;
    if(!pRoot1)
        return false;
    
    if(!Equal(pRoot1->m_dbValue,pRoot2->m_dbValue))
        return false;
    return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft)&&
        DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}



bool HasSubTree(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2)
{
    bool target=false;
    if(pRoot1 && pRoot2)
    {
        if(Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
            target=DoesTree1HasTree2(pRoot1, pRoot2);
        if(!target)
            target=HasSubTree(pRoot1->m_pLeft, pRoot2);
        if(!target)
            target=HasSubTree(pRoot1->m_pRight, pRoot2);
    }
    return target;
}


int main(int argc,char* argv[])
{
     BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
     BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
     BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
     BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
     BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

     ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
     ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
     ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
     ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

     BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
     BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
     BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

     ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
     ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);
    
    bool target=HasSubTree(pNodeA1,pNodeB1);
    cout<<target<<endl;
    
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
    
    return 0;
}
