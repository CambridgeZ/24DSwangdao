//将两个有序表合成一个顺序表

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

SqList fun(SqList list1,SqList list2){
    int len=list1.length+list2.length;
    SqList list;
    list.length = len;
    list.data = new int[len];

    int i=0,j=0,k=0;
    while(i<list1.length&&j<list2.length){
        if(list1.data[i]<list2.data[j])
            list.data[k++]=list1.data[i++];
        else 
            list.data[k++]=list2.data[j++];
    }

    while(i<list1.length){
        list.data[k++]= list1.data[i++];
    }

    while(j<list2.length){
        list.data[k++] = list2.data[j++];
    }

    return list;
}

int main(){
    int n;
    cin>>n;
    SqList list1;
    list1.length=n;
    list1.data = new int[list1.length];
    for(int i=0; i<list1.length; i++){
        cin>>list1.data[i];
    }

    cin>>n;
    SqList list2;
    list2.length=n;
    list2.data=new int[list2.length];
    for(int i=0; i<list2.length; i++){
        cin>>list2.data[i];
    }

    SqList list = fun(list1 , list2);

    show(list);

    return 0;


}