//
// Created by Mac on 2023/1/20.
//
/*
 * 输出二叉排序树上所有值不小于k的值,从大到小
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

void printValueLargerThanK(BiTree T,int k){
    /*
     * 先输出右边的节点的中序遍历,在输出之前先判断，如果出现了小于的时候就及时停止
     */
    BiTree p;
    p=T;
    stack<BiTree> S;
    while(p||!S.empty()){
        if(p){
            S.push(p);
            p=p->rchild;//一路向右
        }
        else{
            p=S.top();
            S.pop();
            if(p->data>=k)
                cout<<p->data<<" ";
            else
                break;
            p=p->lchild;
        }
    }
}


int main(){
    BiTree T;
    CreateBiTree(T);
    int k;
    cin>>k;
    printValueLargerThanK(T,k);
    return 0;
}
