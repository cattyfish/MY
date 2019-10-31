//
//  SelectionSort.cpp
//  Algorithm
//
//  Created by MY on 2019/10/30.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
using namespace std;

void ShellSort(int * array,int length)
{
    for(int gap=length/2;gap>=1;gap--)
    {
        for(int i=gap;i<length;i++)//注意起始索引是gap,这里i的自增值仍然是1，因为理论上虽然是分组进行比较，但是实际还是依次进行比较，不是一组比到底
        {
            int preIndex=i-gap;
            int current=array[i];
            while(preIndex>=0 && array[preIndex]<current)
            {
                array[preIndex+gap]=array[preIndex];
                preIndex-=gap;
            }
            array[preIndex+gap]=current;
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
    ShellSort(array, 6);
    cout<<"after sorted:";
    for(int i=0;i<6;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
