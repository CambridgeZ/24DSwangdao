//删除给定值的s与t之前的所有元素

#include <iostream>
using namespace std;

struct SqList{
    int length;
    int *data;
};

void show(SqList list){//输出顺序表中的元素
    for(int i=0; i<list.length;i++){
        cout<<list.data[i]<<" ";
    }
    cout<<endl;
}

void fun(SqList &list,int s,int t){
    if(list.length==0 || s>=t){
        cout<<"Error"<<endl;
        return ;
    }

    int k=0;
    for(int i=0;i<list.length;i++){
        if(list.data[i]>=s&&list.data[i]<=t)
            continue;
        list.data[k++]=list.data[i];
    }
    list.length=k;
}

int main(){
    int n;
    cin>>n;
    SqList list;
    list.length=n;
    list.data = new int[list.length];
    for(int i=0; i<list.length; i++){
        cin>>list.data[i];
    }

    int s, t;
    cin>> s >> t;

    fun(list,s,t);
    show(list);

    return 0;
}