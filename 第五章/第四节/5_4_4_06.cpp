//
// Created by Mac on 2023/1/15.
//
/*
 * 根据某个树的层序遍历结果和每个节点的度编写
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct BiNode{
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

void CreateTreeByLayerOrderAndDegree(string s1,string s2,BiTree& T){
    /*
     * 行吧，我是有写屎山的天赋的。。。
     */
    vector<vector<BiTree> > layers;
    vector<BiTree> layer;
    BiTree p;
    T=new BiNode;
    T->data=s1[0]-'0';
    T->lchild=T->rchild=NULL;
    layer.push_back(T);
    layers.push_back(layer);//将第一层节点放入

    int nextLayerlength=s2[0]-'0';
    int i=1;
    while(i<s1.length()) {
        layer.clear();
        int thisLayerlength=nextLayerlength;
        nextLayerlength=0;
        for (int j = 0; j < thisLayerlength; i++, j++) {
            BiTree p;
            p= new BiNode;
            p->data= s1[i]-'0';
            p->lchild=NULL,p->rchild==NULL;
            layer.push_back(p);
            nextLayerlength+=s2[i]-'0';
        }
        layers.push_back(layer);
    }

    /*
     * 根据度的关系将节点串起来
     */
    int index=0;
    for(int i=0;i<layers.size()-1;i++){
        for(int j=0;j<layers[i].size();j++){
            int k=0;//标记访问下一行的位置
            int childs=s2[index]-'0';//这个节点的孩子节点的个数
            if(childs!=0){
                layers[i][j]->lchild=layers[i+1][k];
            }
            else{
                layers[i][j]->lchild=NULL;
            }
            for(int l=1;l<childs;l++,k++){
                layers[i+1][k]->rchild=layers[i+1][k+1];
            }
            k++;
            index++;
        }//完成一个节点的处理
    }//完成一层的处理

}

void PreOrder(BiTree T){
    cout<<T->data<<" ";
    if(T->lchild)
        PreOrder(T->lchild);
    if(T->rchild)
        PreOrder(T->rchild);
}

/*
 * 标准答案的代码不想复现了，大同小异，但是在找子节点这块比我更加高明，直接向下去遍历，不用分层，数接下来没遍历到的就是这个树的子节点
 */


int main(){
    BiTree T;
    CreateTreeByLayerOrderAndDegree("1234","3000",T);
    PreOrder(T);
    return 0;
}