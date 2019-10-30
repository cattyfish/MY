//
//  SelectionSort.cpp
//  Algorithm
//
//  Created by MY on 2019/10/30.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
using namespace std;

void SelectionSort(int * array,int length)
{
    for(int i=0;i<length-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<length;j++)//注意这里索引的起始位置，后面所有的数和下标i的数作比较，所以从i+1开始
        {
            if(array[j]>array[minIndex])//注意这里是和下标为minIndex的数作比较，不要错写成i
            {
                minIndex=j;//实时改变最小数的索引，确保每一次查找都是s剩下无序数组中最小/大的数
            }
        }
        int temp=array[minIndex];
        array[minIndex]=array[i];
        array[i]=temp;
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
    SelectionSort(array, 6);
    cout<<"after sorted:";
    for(int i=0;i<6;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
