//
// Created by Mac on 2023/2/7.
//
/*
 * 重写当前的快速排序，让枢轴从当前的子表当中随机产生
 */
#include <iostream>

using namespace std;

int partit(int a[],int low,int high){
    //产生随机数
    int random=rand()%(high-low+1)+low;
    swap(a[random],a[low]);
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

void QuickSort(int a[],int low,int high){
    if(low<high){
        int partition= partit(a,low,high);
        QuickSort(a,partition+1,high);
        QuickSort(a,low,partition-1);
    }
}

void test(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return ;
}

int main(){
    test();
    return 0;
}
