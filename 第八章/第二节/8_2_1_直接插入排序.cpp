//
// Created by Mac on 2023/1/20.
//
#include<iostream>
using namespace std;

void InsertSort(int a[],int n){
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            int p=a[i];
            int j=i-1;
            while(p<a[j]&&j>=0){
                a[j+1]=a[j];//将元素向后移动
                j--;
            }
            a[j+1]=p;//将元素插入
        }
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    InsertSort(a,n);
    printArray(a,n);
    return 0;
}