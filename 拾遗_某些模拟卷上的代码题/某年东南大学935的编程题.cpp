//
// Created by Mac on 2023/12/13.
//
/*
 * 给定一个数组，找出数组中最大的逆序差
 */

#include <iostream>

using namespace std;

int GetMaxReverseGap(int a[],int n){
    int dis[n-1];
    for(int i=0;i<n-1;i++){
        dis[i]=a[i+1]-a[i];
    }

    int sum_now=0;
    int max_sum=0x80000000;
    for(int i=0;i<n-1;i++){
        if(sum_now<=0){
            sum_now=dis[i];
        }
        else{
            sum_now+=dis[i];
        }
        if(sum_now> max_sum)
            max_sum = sum_now;
    }

    return  max_sum;
}

//test
/*
 * 测试数据： 8  4 15 5 6 9 1 16 11
 */
void test(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<GetMaxReverseGap(a,n)<<endl;

}

int main(){
    test();
    return 0;
}


