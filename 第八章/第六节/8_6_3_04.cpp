//
// Created by Mac on 2023/2/18.
//
/*
 * 将最后一个元素放在完成排序之后应该放置的位置上
 */
#include <iostream>
using namespace std;

int putTheLastElementToTheRightPosition(int a[],int n){
    swap(a[0],a[n-1]);
    int x=a[0];
    int low=0,high=n-1;
    while(low<high){
        while(low<high&&a[high]>x)
            high--;
        a[low]=a[high];
        while(low<high&&a[low]<x)
            low++;
        a[high]=a[low];
    }
    a[low]=x;
    return low;
}

void test(){
    int a[]={0,1,2,3,4,5,6,9,8,7};
    int n=sizeof(a)/sizeof(a[0]);
    int index=putTheLastElementToTheRightPosition(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<index<<endl;
}

int main(){
    test();
    return 0;
}
