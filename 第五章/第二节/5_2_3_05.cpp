//
// Created by Mac on 2023/1/5.
//
/*
 * 已知一个二叉树按照顺序存储，求i,j最近的公共祖先节点
 */

int findTheCommonAncesor(int i ,int j){
   while(i!=j){
       if(i>j)
           i=i/2;
       else
           j=j/2;
   }
   return i;
}