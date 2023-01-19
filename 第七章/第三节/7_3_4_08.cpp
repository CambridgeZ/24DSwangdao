//
// Created by Mac on 2023/1/19.
//
/*
 * 判断二叉树是不是二叉平衡树
 */

#include <iostream>
using namespace std;
/*
 * 采用后序遍历的办法求两边子树的高度
 */


typedef struct BiNode{
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

void CreateBiTree(BiTree &T){
    /*
     * 测试数据
     * 1:   2 1 -9999 -9999 3 -9999 -9999
     * 2:   1 2 3 -9999 -9999 4 -9999 -9999 5 -9999 -9999
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

bool isAVL(BiTree T,int &height){
    if(T->lchild==NULL&&T->rchild==NULL){
        height=1;
        return true;
    }

}



int main() {
}