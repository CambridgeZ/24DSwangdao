//
// Created by Mac on 2022/12/28.
//

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

void InOrder(BiTree T){//采用递归实现
    if(T==NULL){
        return ;
    }
    else{
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}

void InOrderByStack(BiTree T){//采用栈来实现，而不是递归来实现遍历
    BiNode* p;
    p=T;
    stack<BiNode*> S;
    while(p||!S.empty()){
        if(p){
            //找到最左端的节点，并且把中间经过的节点都入栈
            S.push(p);//将当前节点入栈
            p=p->lchild;//向左
        }
        else {
            //已经找到了最左边的节点
            p=S.top();
            S.pop();
            cout<<p->data<<" ";
            p=p->rchild;//向右子树走一次
        }
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    InOrder(T);cout<<endl;
    InOrderByStack(T);cout<<endl;
    return 0;
}
