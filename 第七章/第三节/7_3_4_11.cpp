//
// Created by Mac on 2023/1/20.
//
/*
 * 返回一个二叉排序树上第k小的元素的指针，要求BiTree节点中增加一个count节点，作为统计以这个节点为根的子树上的节点的个数的多少
 */
#include <iostream>
using namespace std;

typedef struct BiNode{
    int data;
    int count;
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

int initCount(BiTree &T){
    int count;
    if(T==NULL)
        return 0;
    else{
        count= initCount(T->lchild)+ initCount(T->rchild)+1;
        T->count=count;
        return count;
    }
}

BiTree theKthBNode(BiTree T,int k){
    if(T==NULL)
        return nullptr;
    if(T->lchild!=NULL&&T->lchild->count==k-1||T->lchild==NULL&&k==1)
        return T;
    else if(T->lchild!=NULL&&T->lchild->count>k-1){
        /*
         * 左边的子树上的个数是大于k
         * 说明第k个一定是在左子树上面的，并且这个节点就是左子树的第k个节点
         */
        return theKthBNode(T->lchild,k);
    }
    else {
        /*
         * 第k个元素是右子树上面的，那么这个节点在右子树
         */
        return theKthBNode(T->rchild,k-1-T->lchild->count);
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    initCount(T);
    int key;
    while(cin>>key){
        BiTree p;
        p= theKthBNode(T,key);
        if(p!=NULL)
            cout<<p->data<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}