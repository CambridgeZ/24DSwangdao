//
// Created by Mac on 2023/1/11.
//
/*
 * 求最多的一层的节点的个数
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

int theWidthOfTheTree(BiTree T){
    BiTree p=T;
    struct BiTreeAndLayer{
        BiTree T;
        int layer=0;
    };

    vector<int> layerNumbers;

    queue<BiTreeAndLayer> Q;
    struct BiTreeAndLayer BTL;
    BTL.T=T;
    BTL.layer=1;
    Q.push(BTL);

    while(p&&!Q.empty()){
        if(layerNumbers.size()<Q.front().layer){
            layerNumbers.push_back(0);
        }
        layerNumbers[Q.front().layer-1]++;
        p=Q.front().T;
        if(p->lchild){
            struct BiTreeAndLayer BTL;
            BTL.T=p->lchild;
            BTL.layer=Q.front().layer+1;
            Q.push(BTL);
        }
        if(p->rchild){
            struct BiTreeAndLayer BTL;
            BTL.T=p->rchild;
            BTL.layer=Q.front().layer+1;
            Q.push(BTL);
        }
        Q.pop();
    }

    int max=-1;
    for(auto e:layerNumbers){
        if(e>max)
            max =e;
    }
    return max;
}

int main(){
    BiTree T;
    CreateBiTree(T);
    cout<<theWidthOfTheTree(T)<<endl;
    return 0;
}
