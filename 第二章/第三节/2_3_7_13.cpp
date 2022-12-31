//
// Created by Mac on 2022/12/31.
//
/*
 * 合并两个递增的链表，合成的链表之后得到的递减的链表
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

void mergeTheLists(Node* list1,Node* list2,Node* list3){
    Node* p1= list1->next;
    Node* p2= list2->next;
    Node* p3= list3;
    while(p1&&p2){
        if(p1->data<p2->data){
            list1->next=p1->next;
            p1->next=p3->next;
            p3->next=p1;
            p1=list1->next;
        }
        else {
            list2->next=p2->next;
            p2->next=p3->next;
            p3->next=p2;
            p2=list2->next;
        }
    }
    while(p1){
        list1->next=p1->next;
        p1->next=p3->next;
        p3->next=p1;
        p1=list1->next;
    }
    while(p2){
        list2->next=p2->next;
        p2->next=p3->next;
        p3->next=p2;
        p2=list2->next;
    }
}

int main(){
    Node list1,list2,list3;

    CreateList(&list1);
    PrintList(&list1);
    CreateList(&list2);
    PrintList(&list2);
    mergeTheLists(&list1,&list2,&list3);
    PrintList(&list3);
    return 0;

}