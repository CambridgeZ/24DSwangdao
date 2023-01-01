//
// Created by Mac on 2023/1/1.
//

#include "List_2_3_7_20.h"
#include <iostream>
using namespace std;

void  List_2_3_7_20::CreateList() {
    head->next=NULL;
    int data;
    cin>>data;
    Node * p;
    p=head;
    while(data!=-9999){
        /*
         * 创建双向循环链表
         */
        Node * q;
        q=new Node;
        q->freq=0;
        q->data=data;
        q->next=head;
        q->pre = p;
        p->next = q;
        p=p->next;
        cin>>data;
    }
}

int List_2_3_7_20::lengthOfLinklist() {
    int len=0;
    Node* p= head->next;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

void List_2_3_7_20::PrintList() {
    Node* p= head->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void List_2_3_7_20::Locate(int x) {
    Node* p=head->next;
    while(p->data!=x){
        p=p->next;
    }
    if(p==NULL){
        cout<<"FAIL:The number doesn't exist!"<<endl;
        return ;
    }
    p->freq++;
    Node *q=p->pre;
    /*
     * 按照频率将找到的这个节点放到合适的地方
     */
    while(q->data<=p->freq||q==head){//从当前的位置向前，一直找到比这个节点的频率更大的数字或者到了头节点
        q=q->pre;
    }
    //移动节点
    p->pre->next=p->next;
    p->next->pre=p->pre;

    p->next=q->next;
    q->next=p;
    p->pre=q;
    p->next->pre=p;
}
