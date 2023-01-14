//
// Created by Mac on 2023/1/14.
//
#include <iostream>
using namespace std;

struct BiNode{
    string s="";
    char weight;
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
    char data;
    cin>>data;
    if(data=='#'){
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

void TransInto(BiTree T){
    if(T->left)
        TransInto(T->left);
    if(T->right)
        TransInto(T->right);

    T->s+=T->weight;
    if(T->left)
        T->s=T->left->s+T->s;
    if(T->right)
        T->s=T->s+T->right->s;
}
