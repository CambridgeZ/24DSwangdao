//
// Created by Mac on 2023/2/2.
//

#include <iostream>
using namespace std;

void InsertSort(int a[],int n){
    int i,j,low,high,mid;
    for(int i=1;i<=n;i++){
        int temp=a[i];//保存这次过程当中需要进行插入的值
        low=0,high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(a[mid]>temp)
                high=mid-1;//查找左半子表
            else
                low=mid+1;//查找右半子表
        }
        for(j=i-1;j>=high+1;j--){
            a[j+1]=a[j];
        }
        a[high+1]=temp;
    }
}

void test(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    InsertSort(a,n);
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