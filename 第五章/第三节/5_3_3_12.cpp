//
// Created by Mac on 2023/1/9.
//
/*
 * 打印到达值为x点的路径,其中值为x的节点不多余1个
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

void printTrack(stack<BiTree> S){
    stack<BiTree> Q;
    while(!S.empty()){
        Q.push(S.top());
        S.pop();
    }
    while(!Q.empty()){
        cout<<Q.top()->data<<" ";
        Q.pop();
    }
}

void printTrackOfNodeValueX(BiTree T,int x){
    BiTree p;
    stack<BiTree> S;
    p=T;
    while(p||!S.empty()){
        if(p){
            S.push(p);
            p=p->lchild;
        }
        else{
            p=S.top();
            S.pop();
//            cout<<p->data<<" ";
            if(p->data==x){
                printTrack(S);
                cout<<x<<endl;
                return ;
            }
            p=p->rchild;
        }
    }
}

int main(){
    BiTree T;
    CreateBiTree(T);
    printTrackOfNodeValueX(T,3);
    return 0;
}
