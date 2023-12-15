//
// Created by Mac on 2023/12/15.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};


int width[10];

void levelOrder(TreeNode* T){

    memset(width,0,sizeof (width));

    queue<TreeNode*> QU;
    QU.push(T);
    queue<int> levels;
    levels.push(0);

    while(!QU.empty()){
        TreeNode *t= QU.front();
        QU.pop();
        int this_level=levels.front();
        levels.pop();
        width[this_level]++;
        if(t->left){
            QU.push(t->left);
            levels.push(this_level+1);
        }
        if(t->right){
            QU.push(t->right);
            levels.push(this_level+1);
        }
    }
}

int getWifth(TreeNode* root){
    levelOrder(root);
    int max_width=0;
    for(int i=0;i<10;i++){
        if(width[i]> max_width){
            max_width=width[i];
        }
    }
    return max_width;
}





