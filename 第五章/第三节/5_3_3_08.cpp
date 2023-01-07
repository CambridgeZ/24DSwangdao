//
// Created by Mac on 2023/1/8.
//
/*
 * 计算二叉树中所有有两个分支的节点的个数
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

int countBiNode(BiTree T){
    int count=0;
    if(T->lchild&&T->rchild)
        count++;
    if(T->lchild)
        count=count+ countBiNode(T->lchild);
    if(T->rchild)
        count=count+ countBiNode(T->rchild);
    return count;
}

int main(){
    BiTree T;
    CreateBiTree(T);
    cout<<countBiNode(T)<<endl;
    return 0;
}
