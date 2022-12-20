//将一位数组中的两个线性表整体改变先后顺序

//期望能够达到的时间复杂度为O(n)，空间复杂度为O(1)

#include <iostream>
using namespace std;

void show(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] <<" ";
    }
    cout<<endl;
}

void fun(int a[],int n, int m){
    //先对前n个reverse然后对后m个reverse然后整体reverse

    for(int i=0;i<n/2;i++){
        int t = a[n-i-1];
        a[n-i-1] = a[i];
        a[i]= t;
    }

    for(int i=0;i<m/2;i++){
        int t = a[n+m-i-1];
        a[n+m-i-1] = a[n+i];
        a[i+n]= t;
    }

    for(int i=0; i<(n+m)/2; i++){
        int t =a [i];
        a[i]= a[n+m-i-1];
        a[n+m-i-1] = t;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+m];
    for(int i=0;i<n+m;i++){
        cin>>a[i];
    }

    fun(a,n,m);
    show(a,n+m);

    return 0;

}