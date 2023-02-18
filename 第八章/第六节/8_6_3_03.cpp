//
// Created by Mac on 2023/2/18.
//

#include <iostream>
using namespace std;

//计数排序
void CountingSort(int a[],int n){
    int b[n];
    for(int i=0;i<n;i++){
        int lessThan=0;
        for(int j=0;j<n;j++){
            if(a[j]<a[i])
                lessThan++;
        }
        b[lessThan]=a[i];
    }
}

void test(){
    int a[10]={1,3,5,7,9,2,4,6,8,10};
    CountingSort(a,10);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    test();
    return 0;
}
