//
// Created by Mac on 2023/2/7.
//
/*
 * 双向冒泡排序
 */
#include <iostream>
using namespace std;

void DualBubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        if(i%2){
            for(int j=i;j<n-1;j++){
                if(a[j]>a[j+1])
                    swap(a[j],a[j+1]);
            }
        }
        else{
            for(int j=n-1;j>i;j--){
                if(a[j]<a[j-1])
                    swap(a[j],a[j-1]);
            }
        }
    }
}

void BubbleSort(int a[],int n){
    //双向起泡的冒泡排序
    int low=0,high=n-1;
    bool flag=true;//本轮冒泡排序是否发生了交换的标志，如果没有发生交换就意味着这个时候这个数组已经是有序的了
    while(low<high&&flag){
        flag=false;
        for(int i=low;i<high;i++){//正向冒泡，找到最大者
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                flag=true;
            }
        }
        // 每一次将最大的换到最后的位置
        high--;
        for(int i=high;i>low;i--){//反向冒泡，找到最小者
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                flag=true;
            }
        }
        // 每一次将最小的换到最前的位置
        low++;
    }

}

void test(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    DualBubbleSort(a,n);
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
