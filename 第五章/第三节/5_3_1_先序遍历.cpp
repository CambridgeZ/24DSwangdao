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

void PreOrder(BiTree T){
    if(T==NULL){
        return ;
    }
    else{
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void PreOrderByStack(BiTree T){
    /*
     * 不使用递归实现的先序号遍历
     */
    stack<BiTree> S;
    BiTree p=T;
    while(p||!S.empty()){
        if(p){
            cout<<p->data<<" ";
            S.push(p);
            p=p->lchild;
        }
        else{
            p=S.top();
            S.pop();
            p=p->rchild;
        }
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    PreOrder(T);
    cout<<endl;
    PreOrderByStack(T);
    return 0;
}
