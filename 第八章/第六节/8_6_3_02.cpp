//
// Created by Mac on 2023/2/18.
//

#include <iostream>
using namespace std;

void MakeTheArrayInOrder(int a[],int m,int n){
    /*
     * 算法的基本思想：
     * 设置两个指针i,j，分别指向0和n，即数列中所包含的两个子数列的开头
     * 向后移动指针，将其中比较小的数放入新的数列中
     * 最后将新的数列中的元素复制到原来的数列当中
     *
     * 算法的时间复杂度：O(mn)
     * 算法的空间复杂度：O(m+n)
     */
    int i,j;
    int k=0;
    i=0,j=m;
    int b[m+n];
    while(i<m&&j<m+n){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<m){
        b[k++]=a[i++];
    }
    while(j<m+n){
        b[k++]=a[j++];
    }
    for(i=0;i<m+n;i++){
        a[i]=b[i];
    }
}

void test(){
    int a[10]={1,3,5,7,9,2,4,6,8,10};
    MakeTheArrayInOrder(a,4,6);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    test();
    return 0;
}
