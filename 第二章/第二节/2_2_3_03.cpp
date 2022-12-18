//时间复杂度为O(n)，空间复杂度为O(1)的算法删除线性表中所有值为x的元素

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

void fun(SqList &list, int x){
    int find=0;//记录扫描到当前找到的x的个数

    for(int i=0; i<list.length;i++){
        if(list.data[i]== x){
            find++;
        }
        else{
            list.data [i-find] = list.data [i];
        }
    }
    list.length = list.length - find;
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

    int x;
    cin>>x;//输入需要被删除的元素

    fun(list, x);

    show(list);

    return 0;

}