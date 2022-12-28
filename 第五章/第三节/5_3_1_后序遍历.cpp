//
// Created by Mac on 2022/12/28.
//
#include <iostream>
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

void PostOrder(BiTree T){
    if(T==NULL){
        return ;
    }
    else{
        PostOrder(T->lchild);
        cout<<T->data<<" ";
        PostOrder(T->rchild);
    }
}
int main(){
    BiTree T;
    CreateBiTree(T);
    PostOrder(T);
    return 0;
}