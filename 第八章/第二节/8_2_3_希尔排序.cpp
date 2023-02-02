//
// Created by Mac on 2023/2/2.
//
#include <iostream>
using namespace std;

void ShellSort(int a[],int n){
    for(int dk=n/2/*每次分成子序列的两个元素之间的步长*/;dk>=1;dk=dk/2){
        for(int i=dk;i<=n;i++){
            if(a[i]<a[i-dk]){
                int temp=a[i];//存放哨兵
                int j;
                for(j=i-dk;j>=0&&temp<a[j];j-=dk){
                    /*
                     * 对于其中的一组进行插入排序
                     */
                    a[j+dk]=a[j];
                }
                a[j+dk]=temp;
            }
        }
    }
}

void test(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ShellSort(a,n);
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