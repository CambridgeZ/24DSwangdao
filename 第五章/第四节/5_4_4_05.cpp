//
// Created by Mac on 2023/1/15.
//
/*
 * 求孩子兄弟链表法表示的树的深度
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

/*
 * 和求二叉树的算法的唯一区别，这个向右边的时候深度是不变的只有向左的时候深度改变
 */

int Height(BiTree T,int height){

    if(T->lchild){
        int h=Height(T->lchild,height+1);
        if(h>height)
            height=h;
    }
    if(T->rchild){
        int h=Height(T->rchild,height);
        if(h>height)
            height=h;
    }
    return height;
}

int main(){
    BiTree T;
    CreateBiTree(T);
    cout<<Height(T,1);
    return 0;
}
