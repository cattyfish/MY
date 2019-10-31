//
//  SelectionSort.cpp
//  Algorithm
//
//  Created by MY on 2019/10/30.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
using namespace std;

void InsertionSort(int * array,int length)
{
    for(int i=1;i<length;i++)//假定第一个数字是有序的，从第二个数字开始插入有序数组，所以起始索引是1
    {
        int preIndex=i-1;
        int current=array[i];//这里要用一个变量记录下要插入有序数组的值，因为下面的操作可能会更改array[i]的值
        while(preIndex>=0 && array[preIndex]>current)
        {
            array[preIndex+1]=array[preIndex];
            preIndex--;
        }
        array[preIndex+1]=current;//这里的所以是preIndex+1,不清楚就用2，1举例
    }
}

int main(int argc,char * argv[]){
    int array[6]={7,-2,-8,10,4,33};
    cout<<"before sorted:";
    for(int i=0;i<6;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    InsertionSort(array, 6);
    cout<<"after sorted:";
    for(int i=0;i<6;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
