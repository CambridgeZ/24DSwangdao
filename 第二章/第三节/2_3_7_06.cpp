//
// Created by Mac on 2022/12/25.
//
/**
 * 设计一个算法，对于单链表中单元素进行从小到大单排序操作
 */

#include <iostream>
#include <algorithm>
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

void sort(Node * head){
    Node * p =head->next;
    while(p){
        Node* q;
        q=p->next;
        while(q){
            if(q->data<p->data){
                swap(q->data,p->data);
            }
            q=q->next;
        }
        p=p->next;
    }
}

int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    sort(&head);
    PrintList(&head);
    return 0;
}
