//
// Created by Mac on 2022/12/24.
//
/*
 * 删除链表中最小值的高效算法
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

void DeleteMinNode(Node *head){
    int min = 0x7fffffff;
    Node *p= head;
    Node *r= head->next;
    Node *minNode;
    Node *preMinNode;
    while(r){
        if(r->data<min){
            preMinNode=p;
            minNode=r;
            min=r->data;
        }
        r=r->next;
        p=p->next;
    }
    preMinNode->next=minNode->next;
    delete minNode;
}

int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    DeleteMinNode(&head);
    PrintList(&head);
    return 0;
}
