//
// Created by Mac on 2023/1/16.
//
#include <iostream>
using namespace std;

int BinarySearch(int a[],int n,int key){
    int low=0,high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key){//key在前半部分
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
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
    cout<<BinarySearch(a,n,key)<<endl;
    /*
     * test1:   6   1 3 5 6 7 9     3
     * test2:   9   1 2 3 4 5 6 7 8 9   1
     * test3:   7   1 2 3 4 5 6 7   7
     * test4:   4   1 2 3 4     7
     * test5:   5   1 3 7 9 11      6
     */
    return 0;
}
