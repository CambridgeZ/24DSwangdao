//
// Created by Mac on 2023/1/15.
//
/*
 * 求用二叉链表表示的树叶子节点的个数
 */

#include <iostream>

using namespace std;
typedef struct BiNode{
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

void CreateBiTree(BiTree &T){
    /*
    * 测试数据
    * 1:   1 2 -9999 -9999 3 -9999 -9999
    * 2:   1 2 3 -9999 -9999 4 -9999 -9999 5 -9999 -9999
    * 3:   1 2 -9999 -9999 3 4 -9999 -9999 -9999
    * 4:   1 2 3 -9999 -9999 2 -9999 -9999 5 -9999 -9999
    */
    int data;
    cin>>data;
    if(data==-9999){
        T=nullptr;
        return ;
    }
    else {
        T = new BiNode;
        T->data=data;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void countLeaf(BiTree T,int &count){
    if(T->lchild==NULL)
        count++;
    if(T->lchild)
        countLeaf(T->lchild,count);
    if(T->rchild)
        countLeaf(T->rchild,count);
}

int main(){
    BiTree T;
    CreateBiTree(T);
    int count=0;
    countLeaf(T,count);
    cout<<count<<endl;
    return 0;
}
