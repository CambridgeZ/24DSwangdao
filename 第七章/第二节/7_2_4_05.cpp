//
// Created by Mac on 2023/1/18.
//
/*
 * 写出折半查找的递归算法
 */
#include <iostream>
using namespace std;

int BiSearch(int begin,int end,int key,int a[]){
    if(begin<=end){
        int mid=(begin+end)/2;
        if(a[mid]==key)
            return mid;
        else if(key<a[mid]){
            //关键词在中间位置的左边
            return BiSearch(begin,mid-1,key,a);
        }
        else {
            return BiSearch(mid+1,end,key,a);
        }
    }
    else
        return -1;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    while(key!=-9999){
        cout<<BiSearch(0,n-1,key,a)<<endl;
        cin>>key;
    }
    return 0;
}
