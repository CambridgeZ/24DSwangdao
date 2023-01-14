//
// Created by Mac on 2023/1/5.
//
/*
 * 编写二叉树的后序遍历的非递归算法
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

void PostOrderByStack(BiTree T){
    /*
     * 不使用递归实现的后序遍历
     */
    stack<BiTree> S;
    BiTree p=T;
    BiTree r=NULL;
    while(p||!S.empty()){
        if(p){
            S.push(p);
            p=p->lchild;
        }
        else{
            p=S.top();//读出栈顶的节点
            if(p->rchild&&p->rchild!=r){//如果这个节点有右子树并且右子树没有被访问过
                /*
                 * 如果有右子树并且从右子树返回，那么在访问这个之前的那个节点一定就是右子树的根节点
                 */
                p=p->rchild;//接着访问右子树
            }
            else{
                cout<<p->data<<" ";
                S.pop();
                r=p;//记录最近访问过的节点
                p=NULL;
            }
        }//else
    }//while
}

int main(){
    BiTree T;
    CreateBiTree(T);
    PostOrderByStack(T);
    return 0;
}
