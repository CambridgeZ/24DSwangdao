//
// Created by Mac on 2023/1/20.
//

#include<iostream>
using namespace std;

void Merge(int a[],int low,int mid,int high){

}

void MergeSort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}


int main(){

}