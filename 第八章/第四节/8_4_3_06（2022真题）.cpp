//
// Created by Mac on 2023/5/3.
//
/*
 * 算法思想：
 * 对于这个数列创建大根堆，在创建完成之后将堆顶的元素移出，然后继续建大根堆，这样重复10次，就可以得到10个最大堆元素
 *
 * 算法堆时间负责度为O(logn) 空间复杂度为O(1)
 */

# include <iostream>

using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void heapAdjust(int a[],int i,int n){
    int lchild=2*i+1;
    int rchild=2*i+2;
    int max=i;
    if(i<=n/2){
        if(lchild<=n&&a[lchild]>a[max]){
            max=lchild;
        }
        if(rchild<=n&&a[rchild]>a[max]){
            max=rchild;
        }
        if(max!=i){
            swap(a[i],a[max]);
            heapAdjust(a,max,n);
        }
    }
}

void buildHeap(int a[],int n){
    for(int i=n/2;i>=0;i--){
        heapAdjust(a,i,n);
    }
}

int main(){
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    buildHeap(a,2*n-1);
    for(int i=0;i<n;i++){
        swap(a[0],a[2*n-1-i]);
        heapAdjust(a,0,2*n-2-i);
    }
    for(int i=0;i<n;i++){
        cout<<a[2*n-1-i]<<" ";
    }
    return 0;
}
