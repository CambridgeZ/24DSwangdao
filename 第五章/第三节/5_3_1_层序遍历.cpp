//
// Created by Mac on 2022/12/28.
//
#include <iostream>
#include <queue>

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

void LevelOrder(BiTree T){
    queue<BiTree> Q;
    Q.push(T);
    while(!Q.empty()){
        cout<<Q.front()->data<<" ";
        if(Q.front()->lchild!=NULL)
            Q.push(Q.front()->lchild);
        if(Q.front()->rchild!=NULL)
            Q.push(Q.front()->rchild);
        Q.pop();
    }
    return ;
}

int main(){
    BiTree T;
    CreateBiTree(T);
    LevelOrder(T);
    return 0;
}
