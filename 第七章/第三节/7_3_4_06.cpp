//
// Created by Mac on 2023/1/19.
//
/*
 * 判断 给定的 二叉树是不是二叉排序树
 */

#include <iostream>
#include<vector>

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

void InOrder(BiTree T,vector<int> &s){
    if(T->lchild)
        InOrder(T->lchild,s);
    s.push_back(T->data);
    if(T->rchild)
        InOrder(T->rchild,s);
}

bool isBST(BiTree T){
    vector<int> s;
    InOrder(T,s);
    for(int i=1;i<s.size();i++){
        if(s[i]<=s[i-1])
            return false;
    }
    return true;
}

/****标准答案解答******/
int predt=-1;//全局变量，用于存储当前变量的前驱节点

int judgeBST(BiTree bt){
    int b1,b2;
    if(bt==NULL)
        return 1;//是空树
    else{
        b1= judgeBST(bt->lchild);
        if(b1==0||predt>bt->data){
            return 0
        }
        predt=bt->data;
        b2= judgeBST(bt->rchild);
        return b2;
    }
}


int main(){
    BiTree  T;
    CreateBiTree(T);
    cout<<isBST(T)<<endl;
    return 0;
}
