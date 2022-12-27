//
// Created by Mac on 2022/12/27.
//
/*
 * 和上面一道题的思路基本是一样的，只是将一个链表的尾插法改为了头插法
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
    cout<<minNode->data<<" ";
    preMinNode->next=minNode->next;
    delete minNode;
}

void seperateTheLinklist(Node* head,Node * A,Node * B){
    Node * pre=head,*R1=A,*R2=B;
    Node * p=head->next;
    int i=1;
    while(p){
        if(i%2==1){
            pre->next=p->next;
            R1->next=p;
            p->next=NULL;
            R1=R1->next;
            p=pre->next;
        }
        else {
            pre->next=p->next;
            p->next=B->next;
            B->next=p;
            p=pre->next;
        }
        i++;
    }
}

int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    Node A,B;
    A.next=NULL,B.next=NULL;
    seperateTheLinklist(&head,&A,&B);
    PrintList(&A), PrintList(&B);
    return 0;
}