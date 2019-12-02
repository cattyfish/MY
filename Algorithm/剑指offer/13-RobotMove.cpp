//
//  13-RobotMove.cpp
//  Algorithm
//
//  Created by MY on 2019/11/27.
//  Copyright © 2019 mac. All rights reserved.
//
// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
#include <stdio.h>
#include <iostream>
using namespace std;
bool check(int rows,int cols,int row,int col,int threshold,bool * visited)
{
    bool answer=false;
    if(row>=0 && row<rows && col>=0 && col<cols && !visited[cols*row+col])
    {
        int coord[2]={row,col};
        int totalCount=0;
        for(int i=0;i<2;i++)
        {
            while(coord[i]>0)
            {
                
                totalCount+=(coord[i]%10);
                coord[i]/=10;
            }
        }
        if(totalCount<=threshold)
            answer=true;
    }
    return answer;
}

int movingCountCore(int rows,int cols,int row,int col,int threshold,bool * visited)
{
    int count=0;
    if(check(rows, cols,row, col, threshold,visited))
    {
        visited[cols*row+col]=true;
        //是计算方格内所有可以进入的方格数量，所以这里用的是加法
        count=1+movingCountCore(rows, cols, row+1, col, threshold, visited)
                +movingCountCore(rows, cols, row, col+1, threshold, visited)
                +movingCountCore(rows, cols, row-1, col, threshold, visited)
                +movingCountCore(rows, cols, row, col-1, threshold, visited);
    }
    return count;
}
int movingCount(int threshold,int rows,int cols)
{
    if(rows<1 || cols<1 || threshold<0)
        return 0;
    
    bool* visited=new bool[rows*cols];
    memset(visited, 0, rows*cols);
    
    int count=movingCountCore(rows,cols,0,0,threshold,visited);
    
    delete [] visited;
    
    return count;
}

int main(int argc,char* argv[])
{
    cout<<movingCount(15, 20, 20)<<endl;
    return 0;
}
