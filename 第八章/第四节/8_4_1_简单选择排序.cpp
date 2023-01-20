//
// Created by Mac on 2023/1/20.
//
#include <iostream>
using namespace std;

void selectSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min])
                min=j;
        if(min!=i)
            swap(a[i],a[min]);//将无序的元素中最小的一个元素放到最前的位置
    }
}

void printArray(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    selectSort(a,n);
    printArray(a,n);
    return 0;
}