//
// Created by Mac on 2023/1/17.
//

#include <iostream>
using namespace std;

int search(int a[],int n,int key){
    a[0]=key;//将第一个元素作为哨兵，从后向前比较，这样在查找的过程中不必再每次查找的过程当中进行越界检查
    int i=n;
    while(a[i]!=key){
        i--;
    }
    return i;
}

void test(){
    /*
     * test1:   5   3 2 1 7 9   6
     */
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    int posi= search(a,n,key);
    if(posi==0)
        cout<<"false"<<endl;
    else
        cout<<posi<<endl;
    return ;
}

int main(){
    test();
    return 0;
}
