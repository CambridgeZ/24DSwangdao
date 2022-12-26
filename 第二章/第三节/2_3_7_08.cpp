//
// Created by Mac on 2022/12/26.
//

/*
 * 寻找两个链表对公共节点
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>
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

int lengthOfLinkList(Node* head){//求出链表长度
    int i=0;
    Node* p;
    p=head;
    while(p->next){
        p=p->next;
        i++;
    }
    return i;
}

void CreateLinkListWithCommonNode(Node* head1,Node* head2){
    Node * p;
    p=head1;
    while(p->next)
        p=p->next;
    ::srand((unsigned )::time(NULL));
//    int randomNumber = rand()% lengthOfLinkList(head2);
    int randomNumber = 2;
    Node* q=head2->next;
    while(randomNumber--){
        q=q->next;
    }
    p->next=q;
}

void findSameNode(Node* head1,Node* head2){//我自己写比较蛮力的算法
    Node *p1,*p2;
    p1=head1->next;
    while(p1){
        p2=head2->next;
        while(p2){
            if(p2==p1){
                cout<<"Find it! The value is "<<p1->data<<endl;
                return ;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

void Search1stCommon(Node* head1,Node* head2){//时间复杂度为O(l1+l2)的算法
    int len1= lengthOfLinkList(head1),len2 = lengthOfLinkList(head2);
    Node *p1=head1,*p2=head2;
    if(len1>len2){
        while(len1>len2) {
            len1--;
            p1 = p1->next;
        }
    }
    else {
        while(len2>len1) {
            len2--;
            p2 = p2->next;
        }
    }
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
    if(p1){
        cout<<"Find it! The value is "<<p1->data<<endl;
    }
}

int main(){
    Node head1,head2;
    CreateList(&head1), CreateList(&head2);
    PrintList(&head1), PrintList(&head2);
    CreateLinkListWithCommonNode(&head1,&head2);
    PrintList(&head1), PrintList(&head2);
    findSameNode(&head1,&head2);
    Search1stCommon(&head1,&head2);
    return 0;
}