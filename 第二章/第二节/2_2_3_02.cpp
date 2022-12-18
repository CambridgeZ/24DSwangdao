#include <iostream>
using namespace std;

void reverse(int a[],int n){
    if(n==0){
        return;
    }
    for(int i=0;i<n/2;i++){
        //对换
        int t;
        t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
}

void show(int a[],int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    reverse(a,n);
    show(a,n);

    return 0;
}