//
// Created by Mac on 2023/2/7.
//
/*
 * 找到从小到大第k小的元素
 */
#include <iostream>
using namespace std;

int partition(int a[],int low,int high){
    int pivot=a[low];//作为枢轴承的数字
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

int QuickSort(int a[],int low,int high,int k){
    if(low<=high){
        int patition = partition(a,low,high);
        if(patition==k-1){
            return a[k-1];
        }
        if(patition<k-1){
            return QuickSort(a,patition+1,high,k);
        }
        else
            return QuickSort(a,low,patition-1,k);
    }
}

void test(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    cout<<QuickSort(a,0,n-1,k)<<endl;
}



int main(){
    test();
    return 0;
}
