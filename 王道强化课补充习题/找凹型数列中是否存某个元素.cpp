//
// Created by Mac on 2023/4/30.
//
# include <iostream>
# include <algorithm>

using namespace std;

//对于正序的二分查找

bool binary_search(int a[],int begin,int end,int key){
    int mid;
    while(begin<=end){
        mid=(begin+end)/2;
        if(a[mid]==key){
            return true;
        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else{
            begin=mid+1;
        }
    }
    return false;
}

//对于减序的二分查找

bool binary_search2(int a[],int begin,int end,int key){
    int mid;
    while(begin<=end){
        mid=(begin+end)/2;
        if(a[mid]==key){
            return true;
        }
        else if(a[mid]>key){
            begin=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return false;
}

bool findInTheArray(int n,int a[],int key){
    if(binary_search(a,0,n-1,key)||binary_search2(a,n,2*n,key)){
        return true;
    }
    else{
        return false;
    }
}


