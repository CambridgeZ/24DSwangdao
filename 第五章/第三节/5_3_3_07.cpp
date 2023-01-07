//
// Created by Mac on 2023/1/8.
//
/*
 * 判断二叉链表是不是完全二叉树
 */

#include <iostream>
#include <queue>

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

bool isCompleteBiTree(BiTree T){
    queue<BiTree> Q;
    bool isLeaF = false;
    Q.push(T);
    BiTree p;
    while(!Q.empty()){
        p=Q.front();
        Q.pop();
        if(p->lchild==NULL&&p->rchild==NULL){
            if(isLeaF){
                continue;
            }
            else{
                isLeaF= true;
            }
        }
        else if(p->lchild&&!p->rchild){
            if(isLeaF){
                return false;
            }
            else{
                isLeaF=true;
                Q.push(p->lchild);
            }
        }
        else if(p->lchild&&p->rchild){
            if(isLeaF)
                return false;
            else{
                Q.push(p->lchild);
                Q.push(p->rchild);
            }
        }
        else
            return false;

    }
    return true;
}

int main(){
    BiTree T;
    CreateBiTree(T);
    cout<<isCompleteBiTree(T)<<endl;
    return 0;
}
