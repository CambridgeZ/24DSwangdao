//
// Created by Mac on 2023/1/22.
//
#include <iostream>
using namespace std;
/*
 * 5阶B树的相关实现
 */

#define M 5

struct Node{
    int keys[M-1];//B树当中最多有m-1个关键字
    struct Node* child[M];//最多有m个孩子节点
    int num;//节点中的关键字个数
};

int main(){

}