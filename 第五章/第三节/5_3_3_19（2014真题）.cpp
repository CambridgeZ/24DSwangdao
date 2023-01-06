//
// Created by Mac on 2023/1/6.
//
/*
 * 二叉树的带权路径长度WPL是二叉树中所有的叶子节点的带权路径长度之和
 * 给定了一个二叉树T，采用二叉链表存储
 */

#include <iostream>
using namespace std;

struct BiNode{
    int weight;
    struct BiNode* left;
    struct BiNode* right;
};
typedef BiNode* BiTree;

/*
 * 基本思想：
 *      在先序遍历的基础上进行改编,
 *      设置一个变量，在前序遍历的时候，每遍历到一个点就记录到这一个点前面经过的所有的weight的和
 *      如果到了叶节点，就将这里的值加上WPL，最终输出WPL
 */

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
        T->weight=data;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}

void solveTheWPL(BiTree T,int &WPL,int wieghtHasPast/*当前路径上的weight只和*/){
    wieghtHasPast+=T->weight;
    if(T->left)//遍历左子树
        solveTheWPL(T->left,WPL,wieghtHasPast);
    if(T->right)
        solveTheWPL(T->right,WPL,wieghtHasPast);

    if(T->left==NULL&&T->right==NULL){
        WPL+=wieghtHasPast;
        return ;
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    int WPL=0;
    solveTheWPL(T,WPL,0);
    cout<<WPL<<endl;
    return 0;
}