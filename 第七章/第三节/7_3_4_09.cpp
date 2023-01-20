//
// Created by Mac on 2023/1/20.
//

/*
 * 设计一个算法找出二叉排序树当中最大的和最小的关键字
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
     * 1:   2 1 -9999 -9999 3 -9999 -9999
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

void FindTheMaxAndMinNumberInBST(BiTree T,int &min,int &max){
    BiTree p,q;
    p=q=T;
    while(p->lchild){
        p=p->lchild;
    }
    min=p->data;
    while(q->rchild)
        q=q->rchild;
    max=q->data;
}

int main(){
    BiTree T;
    CreateBiTree(T);
    int min,max;
    FindTheMaxAndMinNumberInBST(T,min,max);
    cout<<min<<" "<<max<<endl;
    return 0;
}