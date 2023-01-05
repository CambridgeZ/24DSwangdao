//
// Created by Mac on 2023/1/5.
//
/*
 * 编写二叉树的后序遍历的非递归算法
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

void PostOrderByStack(BiTree T){
    /*
     * 不使用递归实现的先序号遍历
     */
    stack<BiTree> S;
    BiTree p=T;
    while(p||!S.empty()){
        if(p){
            S.push(p);
            p=p->lchild;
        }
        else{
            p=S.top();
            S.pop();
            p=p->rchild;
        }
    }
}
