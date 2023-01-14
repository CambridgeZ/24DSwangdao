//
// Created by Mac on 2023/1/13.
//
/*
 * 将二叉树的节点从左到右放入一个链表当中
 */

#include <iostream>
#include <stack>

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

void putTheTreeInLinkList(BiTree &T,BiTree &K){
    BiTree p;
    p=T;
    stack<BiTree> S;
    BiTree Head;
    Head= new BiNode;
    BiTree q=Head;

    while(p||S.empty()){
        if(p){
            S.push(p);
            p=p->lchild;
        }
        else{
            p=S.top();//找到最右边的节点
            q->rchild=p;
            q=q->rchild;
            p=p->rchild;
        }
    }
}

void printTheLinkList(BiTree T){
    BiTree p=T->rchild;
    while(p){
        cout<<p->data<<" ";
        p=p->rchild;
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    BiTree q;
    putTheTreeInLinkList(T,q);
    printTheLinkList(q);
    return 0;
}
