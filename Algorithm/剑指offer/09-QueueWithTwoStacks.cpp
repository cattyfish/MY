//
//  09-QueueWithTwoStacks.cpp
//  Algorithm
//
//  Created by MY on 2019/11/25.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
#include <stdio.h>
#include <iostream>
#include <stack>
#include <exception>
using namespace std;

template<typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    void appendTail(const T&node);
    T deleteHead();
    
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T> CQueue<T>::CQueue(void)
{
    
}

template <typename T> CQueue<T>::~CQueue(void)
{
    
}


template<typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
        while(!stack1.empty())
        {
            T& data=stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size()==0)
    {
        std::logic_error ex("queue is empty");
        throw std::exception(ex);
    }
    T & head=stack2.top();
    stack2.pop();
    
    return head;
}

int main(int argc,char * argv[])
{
    
    CQueue<char> queue;
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');
    
    cout<<queue.deleteHead()<<queue.deleteHead()<<queue.deleteHead()<<endl;
    
    return 0;
}
