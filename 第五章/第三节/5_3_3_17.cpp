//
// Created by Mac on 2023/1/14.
//
/*
 * 设计一个算法判断两个二叉树是否相同
 */

#include <iostream>
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

void isSameBiTree(BiTree T1,BiTree T2,bool& result){
    if(T1->data==T2->data){
        if(T1->lchild!=NULL&&T2->lchild!=NULL){
            isSameBiTree(T1->lchild,T2->lchild,result);
        }
        else if(T1->lchild==NULL&&T2->lchild!=NULL||T2->lchild==NULL&&T1->lchild!=NULL){
            result = false;
            return ;
        }

        if(T1->rchild!=NULL&&T2->rchild!=NULL){
            isSameBiTree(T1->rchild,T2->rchild,result);
        }
        else if(T1->rchild==NULL&&T2->rchild!=NULL||T2->rchild==NULL&&T1->rchild!=NULL){
            result = false;
            return ;
        }
    }
    else{
        result = false;
        return ;
    }
}


int main(){
    BiTree T1,T2;
    CreateBiTree(T1);
    CreateBiTree(T2);
    bool result = true;
    isSameBiTree(T1,T2,result);
    cout<<result<<endl;
    return 0;
}