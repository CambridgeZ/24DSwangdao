//
// Created by Mac on 2023/1/11.
//
/*
 * 找到两个p,q两个节点最近的公共的祖先节点
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


BiTree  findCommonAnsctor(BiTree node1,BiTree node2,BiTree T){
    /*
     * 利用二叉树利用占的后序遍历的时候，栈中的元素全都是这个节点的祖先节点
     */
    int inStack=0;
    BiTree p=T;
    BiTree r=NULL;
    stack<BiTree> S;
    S.push(p);
    while(!p||!S.empty()){
        if(p){
            S.push(p);
            p=p->lchild;
        }
        else {
            p=S.top();
            if(p->rchild!=NULL&&p->rchild!=r){
                p=p->rchild;
            }
            else{
                S.pop();
                if(p==node2||p==node1){
                    inStack++;
                    if(inStack==2){
                        return S.top();
                    }
                }
                r=p;
                p=NULL;
            }
        }
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    BiTree p;
    p= findCommonAnsctor(T->lchild,T->rchild,T);
    cout<<p->data<<endl;
    cout<<T->data<<endl;
    return 0;
}
