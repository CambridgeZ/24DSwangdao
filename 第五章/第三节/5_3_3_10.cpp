//
// Created by Mac on 2023/1/8.
//

/*
 * 求解先序遍历第k个节点的值
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

void findTheKValue(BiTree T,int &value,int k,int &count){
    if(count==k){
        value=T->data;
        return ;
    }
    if(count>k)
        return ;
    if(T->lchild)
        findTheKValue(T->lchild,value,k,++count);
    if(T->rchild)
        findTheKValue(T->rchild,value,k,++count);
}

int main(){
    int value=-1,count=0;
    BiTree T;
    CreateBiTree(T);
    int k;
    cin>>k;
    findTheKValue(T,value,k,++count);
    cout<<value<<endl;
    return 0;
}