//
// Created by Mac on 2023/2/9.
//
#include <iostream>
using namespace std;

int paiti(int a[],int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>pivot)
            high--;
        a[low]=a[high];
        while(low<high&&a[low]<pivot)
            low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

void QuickSort(int a[],int low,int high,int k){
    if(low<high){
        int patition= paiti(a,low,high);
        if(patition==k)
            return ;
        else if(patition>k){
            QuickSort(a,low,patition-1,k);
        }
        else
            QuickSort(a,patition+1,high,k);
    }
}

int getLargestSub(int a[],int n){
    QuickSort(a,0,n-1,n/2);
    int sub=0;
    int i;
    for(i=0;i<n/2;i++){
        sub-=a[i];
    }
    for(;i<n;i++){
        sub+=a[i];
    }
    return sub;
}

void test(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<getLargestSub(a,n)<<endl;
    return ;
}


int main(){
    test();
    return 0;
}
