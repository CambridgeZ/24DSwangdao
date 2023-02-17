//
// Created by Mac on 2023/2/17.
//

#include <iostream>
using namespace std;

void HeapAdjust(int a[],int k,int len){//对于堆进行调整
    a[0]=a[k];//用a[0]暂存a[k]的值
    for(int i=2*k/*向下找这个树上的叶子节点并且对于叶子节点进行调整*/;i<=len;i*=2){
        if(i<len&&a[i]<a[i+1]){
            i++;//这是为了保证i指向的是比较大的那个叶子节点
        }
        if(a[0]>=a[i])
            /*
             * 如果这个时候这里的根节点没有叶子节点大，那么可以退出了
             * ？为什么可以退出：因为树是从下面向上面来处理的，这个时候下面的树都是已经处理好的了
             */
            break;
        else{
            a[k]=a[i];//否则的的话交换根节点和叶子节点的值
            k=i;
        }
    }
    a[k]=a[0];
}

void BuildMaxHeap(int a[],int len){
    for(int i=len/2;i>0;i--){
        /*
         * 从最底层中有子树的节点向上一步步对于堆进行调整，也就是先调整根靠下面的树，然后调整上面的树
         */
        HeapAdjust(a,i/*暂存放现在的根节点的位置*/,len);
    }
}

void HeapSort(int a[],int len){
    BuildMaxHeap(a,len);//先建立一个初使的大根堆
    for(int i=len;i>1;i--){
        swap(a[i],a[1]);//将最大的元素放到最后面
        HeapAdjust(a,1,i-1);//对于剩下的元素进行调整，让这个再次变成一个大根堆
    }
}

void test(){
    int a[10]={0,9,8,7,6,5,4,3,2,1};
    HeapSort(a,9);
    for(int i=1;i<=9;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    test();
    return 0;
}