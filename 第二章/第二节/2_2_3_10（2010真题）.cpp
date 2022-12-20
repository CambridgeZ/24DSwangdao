/*
    将n个整数存放到一位数组R中。设计一个在时间和空间两个方面都尽可能的高效的算法
    将数列中的都想做循环移动p个

    思路：和2_2_3_08的思路类似，做两次翻转之后可以得到结果
*/

#include <iostream>
using namespace std;

void reverse(int a[],int start,int end){
    if(start>end){
        cout<<"Error"<<endl;
        return ;
    }

    int s=start, e = end;
    while(s<e){
        int t= a[s];
        a[s]= a[e];
        a[e]= t;
        s++,e--;
    }
}

void fun(int a[],int n,int t){
    reverse(a,0,t-1);
    reverse(a,t,n-1);
    reverse(a,0,n-1); 
}

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t;
    cin>>t;
    fun(a,n,t);

    print(a,n);
    
    return 0;
}

/*
    3）时间复杂度为O(n)，空间复杂度为O(1)

*/