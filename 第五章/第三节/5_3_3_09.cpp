//
// Created by Mac on 2023/1/8.
//
/*
 * 翻转二叉树
 * PS: 据说homebrew的作者因为这题没有过谷歌的面试，但是谷歌有一半的人都在用他的软件
 */

#include <iostream>
#include <queue>

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

void reverseBiTree(BiTree T){
    if(T==NULL)
        return ;
    BiTree temp=T->rchild;
    T->rchild=T->lchild;
    T->lchild=temp;
    if(T->lchild){//左边递归
        reverseBiTree(T->lchild);
    }
    if(T->rchild)//右边递归
        reverseBiTree(T->rchild);
}

void InOrder(BiTree T){
    if(T->lchild)
        InOrder(T->lchild);
    cout<<T->data<<" ";
    if(T->rchild)
        InOrder(T->rchild);
}

int main(){
    BiTree T;
    CreateBiTree(T);
    InOrder(T);cout<<endl;
    reverseBiTree(T);
    InOrder(T);cout<<endl;

}
