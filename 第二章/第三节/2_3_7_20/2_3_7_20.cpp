//
// Created by Mac on 2023/1/1.
//
/*
 * 一个非循环的双向链表
 * 里面设置一个freq的参数，作为频率，再开始的时候freq初始化为0
 * 整个链表按照freq从高到低排序
 * 相同的freq当中最近靠近的排在最前面
 */
#include <iostream>
#include "List_2_3_7_20.h"
using namespace std;
int main(){
    List_2_3_7_20 list = List_2_3_7_20();
    list.CreateList();
    list.PrintList();
    int x;
    while(cin>>x){
        list.Locate(x);
        list.PrintList();
    }
    return 0;
}

