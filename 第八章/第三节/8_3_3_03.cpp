//
// Created by Mac on 2023/2/9.
//
#include <iostream>

using namespace std;
/*
 * 线性表按照顺序存储，要求把所有的奇数移动到偶数的前面，要求使占用的空间最小、时间复杂度最小
 */

void OddFirstEvenSecond(int a[],int n){
    /*
     * 双指针，一个前面全是奇数、一个后面全是偶数
     */
    int low=0,high=n-1;
    while(low<high){
        while(a[low]%2)
            low++;
        while(a[high]%2==0)
            high--;
        if(low>=high)
            break;
        else
            swap(a[low],a[high]);
    }

}//O(n)是最佳的方法


void test(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    OddFirstEvenSecond(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    test();
    return 0;
}
