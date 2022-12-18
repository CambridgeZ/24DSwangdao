#include <iostream>
using namespace std;

struct SqList{
    int length;
    int *a;
};
int fun(SqList &list){
    int min=0x3fffffff,min_posi=-1;
    if(list.length<=0){//如果线性表为空则报错
        cout<<"Error"<<endl;
        return -1;
    }
    //找到最小值所在的位置
    for(int i=0;i<list.length;i++){
        if(list.a[i]<min){
            min = list.a[i];min_posi=list.a[i];
        }
    }

    list.a[min_posi] = list.a[list.length-1];
    list.length--;
    return min;
}

int main(){
    int n;
    cin>>n;
    SqList list;
    list.length=n;
    list.a = new int[list.length];
    for(int i=0;i<list.length;i++){
        cin>>list.a[i];//输入数据
    }
    cout<<fun(list)<<endl;

    return 0;


}