//
//  FindInPartiallySortedMatrix.cpp
//  Algorithm
//
//  Created by MY on 2019/11/12.
//  Copyright © 2019 mac. All rights reserved.
//

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
#include <stdio.h>
#include <iostream>
using namespace std;
bool Find(int matrix[][4],int rows,int columns,int number)
{
    bool found=false;
    if(matrix!=nullptr && rows>0 && columns>0)
    {
        int row=0;
        int column=columns-1;
        while(row<rows && column>=0)
        {
            if(matrix[row][column]>number){
                column--;
            }else if(matrix[row][column]<number){//主要是这里的部分，大于这个数后，就增加行的值
                row++;
            }else{
                found=true;
                break;
            }
        }
    }
    return found;
}

int main(int argc,char*argv[])
{
    cout<<"Hello World!!"<<endl;
    int matrix[][4]={{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout<<Find(matrix,4,4,1)<<endl;;
    return 0;
}
