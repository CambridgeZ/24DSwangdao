//
// Created by Mac on 2022/12/25.
//

/**
 * 删除在链表中给定单两个值之间的元素
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

void DeleteCertainNode(Node *head,int lowwer,int higher){
    Node *p= head;
    Node *r= head->next;
    while(r){
        if(r->data>=lowwer&&r->data<=higher){
            p->next=r->next;
            delete r;
            r=p->next;
            continue;
        }
        r=r->next;
        p=p->next;
    }
}

int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    int a,b;
    cin>>a>>b;
    DeleteCertainNode(&head,a,b);
    PrintList(&head);
    return 0;
}