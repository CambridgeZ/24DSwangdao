//
// Created by Mac on 2023/2/17.
//

#include <iostream>
using namespace std;
/*
 * 判断一个数据序列是不是小根堆
 */
bool isMinHeap(int a[],int n){
    for(int i=1;i*2<=n;i++){
        if(a[i]>=a[2*i])//如果根比左节点大，错误的
            return false;
        if(2*i+1<=n){//如果有右节点，比右节点大，错误的
            if(a[i]>=a[i*2+1])
                return false;
        }
    }
    return true;
}

void test(){
    /*
     * 测试数据
     * 10 1 2 3 4 5 6 7 8 9 10
     * 10 10 9 8 7 6 5 4 3 2 1
     */
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(isMinHeap(a,n))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main(){
    test();
    return 0;
}

