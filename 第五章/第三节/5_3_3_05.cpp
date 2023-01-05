//
// Created by Mac on 2023/1/5.
//
/*
 * 设计一个非递归的算法求二叉树的高度
 */

#include <iostream>
#include <cmath>
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

/*
 * 先写一个递归的求高度的算法找找思路吧
 */

int Height(BiTree T,int height){
    height++;
    if(T->lchild==NULL&&T->rchild==NULL){
        return height;
    }
    int leftHeight=0, rightHeight=0;
    if(T->lchild){
        leftHeight= Height(T->lchild,height);
    }
    if(T->rchild){
        rightHeight= Height(T->rchild,height);
    }

    return max(leftHeight,rightHeight);
}

/*
 * 再来写一个不用递归的算法
 */

int HeightByStack(BiTree T){
    stack<BiTree> S;
    stack<int> stackOfHeight;
    BiTree p=T;
    int height=1,maxheight=0;
    while(p||!S.empty()){
        if(p){
            if(height>maxheight)
                maxheight=height;
            S.push(p);
            stackOfHeight.push(height);
            p=p->lchild;
            height++;
        }
        else{
            p=S.top();
            height=stackOfHeight.top();
            S.pop();
            stackOfHeight.pop();
            p=p->rchild;
            if(p)
                height++;
        }
    }

    return maxheight;
}



int main(){
    BiTree T;
    CreateBiTree(T);
    cout<<Height(T,0)<<endl;
    cout<<HeightByStack(T)<<endl;
    return 0;
}