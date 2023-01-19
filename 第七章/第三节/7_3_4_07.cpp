//
// Created by Mac on 2023/1/19.
//
/*
 * 设计一个算法给出指定的节点在二叉排序树的层次
 */
#include <iostream>
using namespace std;

typedef struct BiNode{
    int data;
    struct BiNode* lchild;
    struct BiNode* rchild;
}*BiTree;

BiTree BSTSearch(BiTree T,int key){
    //查找
    if(T==NULL)
        return NULL;
    if(T->data==key)
        return T;
    else if(T->data>key){
        //去左子树上去寻找
        return BSTSearch(T->lchild,key);
    }
    else{
        //去右子树去寻找
        return BSTSearch(T->rchild,key);
    }
}

bool BSTInsert(BiTree &T,int key){
    //插入
    if(T==NULL){
        //空节点的时候开始插入
        T = new BiNode;
        T->data=key;
        T->lchild=NULL;
        T->rchild=NULL;
        return true;
    }
    else if(T->data==key){
        //排序树中有了这个节点，插入失败
        return false;
    }
    else if(T->data>key){
        //在左子树中的某个地方插入
        return BSTInsert(T->lchild,key);
    }
    else {
        return BSTInsert(T->rchild,key);
    }
}

void CreateBST(BiTree &T){
    //创建二叉排序树
    int n;
    cin>>n;
    while(n!=-9999){
        BSTInsert(T,n);
        cin>>n;
    }
}

void DeleteNodeInBST(BiTree T,int key){
    if(T->data==key){
        if(T->lchild==NULL&&T->rchild==NULL){
            //叶子节点，直接删除
            delete T;
        }
        else if(T->lchild==NULL){
            //只有右子树
            BiTree p=T;
            T=T->rchild;
            delete p;
        }
        else if(T->rchild==NULL){
            //只有左子树
            BiTree p=T;
            T=T->lchild;
            delete p;
        }
        else {
            //左右两边都有，让直接后继放在T的位置，去删除直接后继
            T->data=T->rchild->data;
            DeleteNodeInBST(T->rchild,T->rchild->data);
        }
    }
    else if(T->data>key){
        DeleteNodeInBST(T->lchild,key);
    }
    else if(T->data<key){
        DeleteNodeInBST(T->rchild,key);
    }
}

int rTheLayer(int data,BiTree T){
    /*
     * 采用递归的算法
     */
    if(T==NULL)
        return -1;
    if(T->data==data)
        return 1;
    else if(T->data>data)
        return 1+ rTheLayer(data,T->lchild);
    else
        return 1+ rTheLayer(data,T->rchild);
}

int level(BiTree T,int data){
    /*
     * 不用递归的算法
     */

    BiTree p=T;
    int layer=1;
    while(p!=NULL&&p->data!=data){
        layer++;
        if(p->data>data){
            p=p->lchild;
        }
        else{
            p=p->rchild;
        }
    }
    if(p==NULL)
        return -1;
    else
        return layer;
}

int main(){
    BiTree T=NULL;
    CreateBST(T);
    int key;
    while(cin>>key){
        if(key==-9999)
            break;
        cout<<rTheLayer(key,T)<<endl;
    }
    return 0;
}
