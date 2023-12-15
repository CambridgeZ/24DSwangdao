//
// Created by Mac on 2023/12/15.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

int WPL=0;
void PreOrder(TreeNode* root,int height){
    if(root->right==NULL&&root->left==NULL){
        WPL=WPL+(height*root->data);
    }
    else {
        if(root->left){
            PreOrder(root->left,height+1);
        }
        if(root->right){
            PreOrder(root->right,height+1);
        }
    }
}

int getWPL(TreeNode* root){
    PreOrder(root,0);
    return WPL;
}

//create WPL
TreeNode* createWPL(){
    TreeNode* root=new TreeNode;
    root->data=1;
    root->left=NULL;
    root->right=NULL;

    TreeNode* node1=new TreeNode;
    node1->data=2;
    node1->left=NULL;
    node1->right=NULL;

    TreeNode* node2=new TreeNode;
    node2->data=3;
    node2->left=NULL;
    node2->right=NULL;

    TreeNode* node3=new TreeNode;
    node3->data=4;
    node3->left=NULL;
    node3->right=NULL;

    TreeNode* node4=new TreeNode;
    node4->data=5;
    node4->left=NULL;
    node4->right=NULL;

    TreeNode* node5=new TreeNode;
    node5->data=6;
    node5->left=NULL;
    node5->right=NULL;

    TreeNode* node6=new TreeNode;
    node6->data=7;
    node6->left=NULL;
    node6->right=NULL;

    TreeNode* node7=new TreeNode;
    node7->data=8;
    node7->left=NULL;
    node7->right=NULL;

    TreeNode* node8=new TreeNode;
    node8->data=9;
    node8->left=NULL;
    node8->right=NULL;

    TreeNode* node9=new TreeNode;
    node9->data=10;
    node9->left=NULL;
    node9->right=NULL;

    TreeNode* node10=new TreeNode;
    node10->data=11;
    node10->left=NULL;
    node10->right=NULL;

    TreeNode* node11=new TreeNode;
    node11->data=12;
    node11->left=NULL;
    node11->right=NULL;

    TreeNode* node12=new TreeNode;
    node12->data=13;
    node12->left=NULL;
    node12->right=NULL;

    TreeNode* node13=new TreeNode;
    node13->data=14;
    node13->left=NULL;
    node13->right=NULL;

    TreeNode* node14=new TreeNode;
    node14->data=15;
    node14->left=NULL;
    node14->right=NULL;

    TreeNode* node15=new TreeNode;
    node15->data=16;
    node15->left=NULL;
    node15->right=NULL;

    TreeNode* node16=new TreeNode;
    node16->data=17;
    node16->left=NULL;
}

//test
int main(){
    TreeNode* root=createWPL();
    cout<<getWPL(root)<<endl;
    return 0;
}

