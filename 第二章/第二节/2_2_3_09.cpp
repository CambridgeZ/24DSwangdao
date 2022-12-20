//在递增数列中查找一个元素，如果找到将这个元素和后继交换顺序

#include <iostream>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int search(int a[],int n,int x){//二分查找
    int low = 0, high = n-1;
    int mid;

    while(low<=high){
        int mid =(low + high) / 2;
        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]<x){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return -1;
}

void fun(int a[],int n, int x){
    int position = search(a,n,x);
    if(position== -1){
        cout<<"Error"<<endl;
        return ;
    }
    else if(position==n-1){
        return ;
    }
    else {
        int t;
        t= a[position];
        a[position]= a[position+1];
        a[position+1]= t;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>> a[i];

    int x;
    cin>>x;

    fun(a , n ,x);

    print(a,n);

    return 0;

}