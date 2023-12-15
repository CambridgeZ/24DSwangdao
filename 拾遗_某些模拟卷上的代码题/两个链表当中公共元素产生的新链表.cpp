//
// Created by Mac on 2023/12/15.
//
#include <iostream>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

void LinkListOfCommonEle(ListNode* head1,ListNode* head2){
    ListNode *p,*q;
    ListNode* head3 = new ListNode;
    ListNode *r= head3;
    while(p&&q){
        if(p->data<q->data){
            p=p->next;
        }
        else if(p->data>q->data){
            q=q->next;
        }
        else {
            ListNode* newNode= new ListNode;
            newNode->data=p->data;
            newNode->next= NULL ;
            r->next= newNode;
            r=r->next;
        }
    }
}