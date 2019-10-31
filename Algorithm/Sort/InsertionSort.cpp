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
    for(int i=1;i<length;i++)
    {
        int preIndex=i-1;
        int current=array[i];
        while(preIndex>=0 && array[preIndex]>current)
        {
            array[preIndex+1]=array[preIndex];
            preIndex--;
        }
        array[preIndex+1]=current;
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
