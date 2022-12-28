//
// Created by Mac on 2022/12/28.
//
#include <iostream>

using namespace std;
typedef struct BiNode{
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;

void CreateBiTree(ThreadTree &T){
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

void InThread(ThreadTree &p,ThreadTree &pre/*当前的这个节点的前驱节点*/){
    if(p){
        InThread(p->lchild,pre);//线索化左子树

        if(p->lchild!=NULL){
            /*
             * 左孩子不是空的，这个时候只需要将tag位标记为这个地方是孩子节点即可
             */
            p->ltag=0;
        }
        else{
            p->ltag=1;
            /*
             * 将左孩子指向前驱节点
             */
            p->lchild=pre;
        }

        if(pre->rchild!=NULL){
            /*
             * 这里线索化的不是p节点而是pre节点
             * 右孩子不是空的，这个时候只需要将tag位标记为这个地方是孩子节点即可
             */
            pre->ltag=0;
        }
        else{
            pre->ltag=1;
            /*
             * 将右孩子指向后继节点
             */
            pre->rchild=p;
        }

        pre =p;//当前节点将成为其右孩子的前驱（如果有的话）
        InThread(p->rchild,pre);//线索化右子树
    }
}

void CreateInThread(ThreadTree& T){//创建线索树的函数
    ThreadNode head;//这个线索链表的头节点
    ThreadTree H =&head;
    ThreadTree p;
    p=T;
    InThread(p,H);
}

ThreadNode *FirstNode(ThreadNode* T){//一路向左找到最左边的节点
    ThreadNode *p=T;
    while(p->ltag==0)
        p=p->lchild;
    return p;
}

ThreadNode *NextNode(ThreadNode* T){
    //求解当前节点的后继
    if(T->rtag==0){
        return FirstNode(T->rchild);
    }
    else {
        return T->rchild;
    }
}

void InOrder(ThreadNode * T){
    for(ThreadNode *p= FirstNode(T);p!=NULL;p= NextNode(p))
        cout<<p->data<<" ";
    return ;
}