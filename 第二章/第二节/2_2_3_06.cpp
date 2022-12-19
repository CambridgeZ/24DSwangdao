/*
    在有序顺序表中删除重复的元素使所有元素的值都不同
    注意：操作限定的背景是在有序顺序表中
*/

#include <iostream>
using namespace std;

struct SqList{
    int length;
    int *data;
};

void show(SqList list1){//输出顺序表中的元素
    for(int i=0; i<list1.length;i++){
        cout<<list1.data[i]<<" ";
    }
    cout<<endl;
}

void fun(SqList &list1){
    if(list1.length<=0){
        cout<<"Error"<<endl;
        return ;
    }

    int k=1;
    for(int i=1; i<list1.length;i++){
        if(list1.data[i]>list1.data[i-1]){
            list1.data[k++]=list1.data[i];
        }
    }

    list1.length=k;
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

    fun(list1);
    show(list1);

    return 0;


}