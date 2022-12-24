//
// Created by Mac on 2022/12/24.
//
/*
 * 将带头节点的单链表原地逆置
 */

#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void CreateList(Node * head){
    int data;
    cin>>data;
    Node * p;
    p=head;
    while(data!=-9999){
        Node * q;
        q=new Node;
        q->data=data;
        q->next=nullptr;
        p->next = q;
        p=p->next;
        cin>>data;
    }
}

void PrintList(Node *head){
    Node* p= head->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

Node* Reverse_1(Node *head){//将头节点摘下，将后面的节点使用头插法依次插入到头节点的前面
    Node *p,*r;
    p=head->next;
    head->next=NULL;
    while(p){
        r=p->next;
        p->next=head->next;
        head->next=p;
        p=r;
    }
    return head;
}


int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    Reverse_1(&head);
    PrintList(&head);
    return 0;
}
