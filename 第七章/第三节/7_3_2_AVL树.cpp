//
// Created by Mac on 2023/1/18.
//
#include <iostream>
using namespace std;

typedef struct BiNode{
    int data;
    struct BiNode *lchild,*rchild;
}* BiTree;

/*
 * 只有左孩子才能右上旋，只有右孩子才能左上旋
 * 旋转可以让孩子编程爹，原来的爹变成现在孩子的孩子
 */


void LL(BiTree gf,BiTree f/*父节点*/,BiTree p/*左孩子*/){
    //左子树的左边子树上插入导致失去平衡
    f->lchild = p->rchild;//A的左子树挂上B的右子树
    p->rchild=f;//A节点成为B的右孩子
    if(gf->lchild==f)
        gf->lchild=p;
    else
        gf->rchild=p;
}

void RR(BiTree gf,BiTree f/*父节点*/,BiTree p/*右孩子*/){
    //右子树的右节点插入导致失去平衡
    f->lchild=p->lchild;//A的右子树挂上B的右子树
    p->lchild=f;//A 节点成为B的左孩子
    if(gf->lchild==f)
        gf->lchild=p;
    else
        gf->rchild=p;
}

void LR(){
    //先左旋后右旋
    RR();
    LL();
}

void RL(){
    //先右旋后左旋
    LL();
    RR();
}


int main(){

}