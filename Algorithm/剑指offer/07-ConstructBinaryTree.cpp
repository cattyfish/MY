//
//  07-ConstructBinaryTree.cpp
//  Algorithm
//
//  Created by 毛煜 on 2019/11/20.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
#include <stdio.h>
#include <iostream>
using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_pRight;
    BinaryTreeNode():m_nValue(0),m_pLeft(nullptr),m_pRight(nullptr){};
    BinaryTreeNode(int value):m_nValue(value),m_pLeft(nullptr),m_pRight(nullptr){};
};

BinaryTreeNode* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
)
{
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    //判断此节点有没有子节点
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw "Invalid input.";
    }

    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

    //判断中序遍历是否合理
    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw "Invalid input.";

    int leftLength = (int)(rootInorder - startInorder);
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
            startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
            rootInorder + 1, endInorder);
    }

    return root;
}


BinaryTreeNode* Construct(int * preOrder,int * inOrder,int length)
{
    if(preOrder==nullptr || inOrder==nullptr || length<=0)
        return nullptr;
    BinaryTreeNode * target=ConstructCore(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
    return target;
}

int main(int argc,char* argv[])
{
    const int length=7;
    int preOrder[length]={1, 2, 4, 5, 3, 6, 7};
    int inOrder[length]={4, 2, 5, 1, 6, 3, 7};
    BinaryTreeNode* target=Construct(preOrder, inOrder, 7);
    cout<<target->m_pLeft->m_pLeft->m_nValue<<endl;
    return 0;
}
