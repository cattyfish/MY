//
//  BubbleSort.cpp
//  Algorithm
//
//  Created by 毛煜 on 2019/10/30.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
using namespace std;

void BubbleSort(int * array,int length)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=0;j<length-1-i;j++)//注意这里j的边界为length-1-i，因为一直是array[j]和array[j+1]作比较
        {
            if(array[j]>array[j+1])//这里比较的对象是array[j]和array[j+1]，不要写成了array[j]和array[i]做比较
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
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
    BubbleSort(array, 6);
    cout<<"after sorted:";
    for(int i=0;i<6;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
