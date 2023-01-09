//
// Created by Mac on 2023/1/9.
//
/*
 * 在存储的时候从1开始存储
 * 遍历其中所有不是-1的节点，判断在第k个位置上的节点是否满足这个节点比存放在2k位置上的节点(不是-1)的值大，比存放在2k+1上的小
 */

#include <iostream>
//预计最多存放4层
#define MAXN 16

using namespace std;

typedef struct {
    int SqBiTNode[MAXN];
    int ElemNum;//实际占用的数组的个数
}SqBiTree;

bool isBiSearchTree(SqBiTree T){
    int hasProcessedNode=0;
    int index=1;
    while(hasProcessedNode<T.ElemNum){
        if(T.SqBiTNode[index]!=-1){
            if(T.SqBiTNode[index*2+1]==-1||T.SqBiTNode[2*index]==-1||T.SqBiTNode[2*index]<=T.SqBiTNode[index]&&T.SqBiTNode[index*2+1]>=T.SqBiTNode[index])
                ;//什么都不做，这样写为了逻辑上自洽吧，但是很丑
            else
                return false;
            hasProcessedNode++;
        }
        index++;
    }
    return true;
}

void CreateSqBiTree(SqBiTree &T){
    ::memset(T.SqBiTNode,-1,sizeof (T.SqBiTNode));
    std::cin>>T.ElemNum;
    for(int i=0;i<T.ElemNum;i++){
        int position,value;
        cin>>position>>value;
        T.SqBiTNode[position]=value;
    }
    /*
     * test
     * 6    1 40    2 25    3 60    5 30    7 80    11 27
     * 5    1 40    2 50    3 60    5 30    12 35
     */
}

int main(){
    SqBiTree T;
    CreateSqBiTree(T);
    cout<<isBiSearchTree(T)<<endl;
    return 0;

}

/*
 * 答案中给出的操作是从后向前扫描，现在这里是从前向后扫描
 */




