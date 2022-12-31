//
// Created by Mac on 2022/12/31.
//
/*
 * 设计从两个链表生成的新的链表C，但是不要用原来链表的节点，用新的节点来存储新的链表的节点
 */
#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void CreateList(Node * head){
    head->next=nullptr;
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

int lengthOfLinklist(Node * head){
    int len=0;
    Node* p= head->next;
    while(p){
        p=p->next;
        len++;
    }
    return len;
}

void MergeLists(Node* list1,Node* list2,Node* list3){
    Node* p1=list1->next, * p2 =list2->next;
    Node * pre=list3;
    while(p1&&p2){
        Node* p;
        if(p1->data<p2->data){
            p=p1;
            p1=p->next;
        }
        else{
            p=p2;
            p2=p2->next;
        }
        Node* q = new Node;
        q->data =p->data;
        pre->next=q;
        q->next=NULL;
        pre=pre->next;
    }
    while(p1){
        Node* p;
        p=p1;
        p1=p->next;
        Node* q = new Node;
        q->data =p->data;
        pre->next=q;
        q->next=NULL;
        pre=pre->next;
    }
    while(p2){
        Node* p;
        p=p2;
        p2=p2->next;
        Node* q = new Node;
        q->data =p->data;
        pre->next=q;
        q->next=NULL;
        pre=pre->next;
    }
}

int main(){
    Node list1,list2,list3;
    CreateList(&list1), CreateList(&list2);
    list3.next=NULL;
    MergeLists(&list1,&list2,&list3);
    PrintList(&list3);
    return 0;
}
