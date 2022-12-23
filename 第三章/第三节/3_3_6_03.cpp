#include <iostream>
#include <stack>

using namespace std;

int fun(int n,int x){ 
    struct stack{
        int no,val;
    }st[10];
    int top=-1,i;
    int fv1=1,fv2=2*x;

    for(int i=n;i>=2;i--){
        top++;
        st[top].no=i;
    }
    while(top>=0){
        st[top].val = 2*x*fv2-2*(st[top].no-1)*fv1;
        fv1=fv2;
        fv2=st[top].val;
        top--;
    }
    if(n==0)
        return fv1;
    else 
        return fv2;
}

int main(){
    int n;
    cin>>n;
    return 0;
}