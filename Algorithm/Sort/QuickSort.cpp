//
//  SelectionSort.cpp
//  Algorithm
//
//  Created by MY on 2019/11/12.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
using namespace std;

void QuickSort(int * array,int begin,int end)//https://blog.csdn.net/starzyh/article/details/90272347
{
    if(begin<end)
    {
        int low=begin;
        int high=end;
        int pivot=array[begin];
        while(low<high)
        {
            //注意，这里因为前面的基准数 是array[begin]，所以要从右开始向左开始搜索，不然最后也会导致基准数右边有比基准数小的数存在
            while(high>low && array[high]>=pivot)
                high--;
            array[low]=array[high];
            while(low<high && array[low]<=pivot)
                low++;
            array[high]=array[low];
                
        }
        array[low]=pivot;
        QuickSort(array, begin, low-1);
        QuickSort(array, low+1, end);
    }
}



void QuickSort2(int * array,int begin,int end)//https://blog.csdn.net/qq_28584889/article/details/88136498
{
    if(begin<end)
    {
        int i=begin;
        int j=end;
        int key=array[begin];
        while(i<j)
        {
            //注意，前面的基准数是array[begin]，所以这里要先从右开始向左查找第一个小于基准的数,不然在下面1步骤的地方会把大于基准的数与基准数进行交换
            while(i<j && array[j]>=key)
                j--;
            while(i<j && array[i]<=key)
                i++;
            if(i<j)
            {
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
        int temp=array[i];//11111111
        array[i]=key;
        array[begin]=temp;
        
        QuickSort2(array, begin, i-1);
        QuickSort2(array, i+1, end);
    }
}


int main(int argc,char * argv[]){
    int array[6]={7,-2,-8,33,4,33};
    int temp=2;
    cout<<array[temp--]<<endl;
    cout<<"before sorted:";
    for(int i=0;i<6;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    QuickSort(array,0, 5);
    cout<<"after sorted:";
    for(int i=0;i<6;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
