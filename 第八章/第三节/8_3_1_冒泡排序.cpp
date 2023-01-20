//
// Created by Mac on 2023/1/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

void BubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        bool flag=false;//本轮冒泡排序是否发生了交换的标志，如果没有发生交换就意味着这个时候这个数组已经是有序的了

        for(int j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
            }
        }

        if(!flag)
            return ;
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    BubbleSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}