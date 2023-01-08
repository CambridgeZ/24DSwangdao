//
// Created by Mac on 2023/1/8.
//
/*
 * 删除节点值为x的节点的子树
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

void findTheKValue(BiTree T,int &value,int k,int &count){
    if(count==k){
        value=T->data;
        return ;
    }
    if(count>k)
        return ;
    if(T->lchild)
        findTheKValue(T->lchild,value,k,++count);
    if(T->rchild)
        findTheKValue(T->rchild,value,k,++count);
}

void deleteBiTree(BiTree T){
    if(T->lchild){
        deleteBiTree(T->lchild);
        T->lchild=NULL;
    }
    if (T->rchild) {
        deleteBiTree(T->rchild);
        T->rchild=NULL;
    }
    delete T;
}

void deleteDateValueEqualToX(BiTree T,int x){
    if(T->data==x)
        deleteBiTree(T);
    else {
        if (T->lchild) {
            if (T->lchild->data == x) {
                deleteDateValueEqualToX(T->lchild, x);
                T->lchild=NULL;
            }
            else{
                deleteDateValueEqualToX(T->lchild, x);
            }
        }
        if (T->rchild) {
            if (T->rchild->data == x) {
                deleteDateValueEqualToX(T->rchild, x);
                T->rchild=NULL;
            }
        }
        else{
            deleteDateValueEqualToX(T->rchild, x);
        }
    }
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
    int x=2;
    deleteDateValueEqualToX(T,2);
    InOrder(T),cout<<endl;
    return 0;
}
