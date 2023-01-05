//
// Created by Mac on 2023/1/5.
//
/*
 * 实现二叉树自下而上，自右向左的层序遍历
 */
#include <iostream>
#include <queue>
#include <stack>

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

void reverseLevelOrder(BiTree T){
    queue<BiTree> Q;
    stack<BiTree> S;
    Q.push(T);
    while(!Q.empty()){
        BiTree temp=Q.front();
        S.push(temp);
        Q.pop();
        if(temp->lchild)
            Q.push(temp->lchild);
        if(temp->rchild)
            Q.push(temp->rchild);
    }

    while(!S.empty()){
        cout<<S.top()->data<<" ";
        S.pop();
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    reverseLevelOrder(T);
    return 0;
}

