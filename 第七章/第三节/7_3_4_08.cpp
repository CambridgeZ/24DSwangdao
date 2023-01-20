//
// Created by Mac on 2023/1/19.
//
/*
 * 判断二叉树是不是二叉平衡树
 */

#include <iostream>
#include <cmath>
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
     * 2:   3 4 5 -9999 -9999 1 -9999 -9999 2 -9999 -9999
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
    if(T==NULL){
        height=0;
        return true;
    }
    int height1=0,height2=0;
    int isAVLleft= false,isAVLright=false;
    isAVLleft= isAVL(T->lchild,height1);
    isAVLright=isAVL(T->rchild,height2);
    if(!(isAVLleft&&isAVLright)){//左右子树当中有一个不是AVL就不是AVL
        return false;
    }
    else {
        if(abs(height2-height1)<=1){//左右子树高度相差小于1
            height=max(height1,height2)+1;
            return true;
        }
        else {
            return false;
        }
    }
}



int main() {
    BiTree T;
    CreateBiTree(T);
    int height=0;
    cout<<isAVL(T,height)<<endl;
    return 0;
}