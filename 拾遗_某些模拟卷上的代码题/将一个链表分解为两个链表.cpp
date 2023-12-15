//
// Created by Mac on 2023/12/15.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

void divideLinkList(ListNode* head){
    ListNode* head1= new ListNode,*head2= new ListNode;
    int index=1;
    ListNode *p, *q;
    p=head1, q=head2;
    while(head->next){
        if(index%2){
            p->next=head->next;
            head->next=head->next->next;
            p=p->next;
            p->next=NULL;
        }
        else {
            q->next = head->next;
            head->next= head->next ->next;
            q=q->next;
            q->next=NULL;
        }
    }
}

void divideLinkList2(ListNode* head){
    ListNode* head1= new ListNode,*head2= new ListNode;
    int index=1;
    ListNode *p, *q;
    p=head1, q=head2;
    while(head->next){
        if(index%2){
            p->next=head->next;
            head->next=head->next->next;
            p=p->next;
            p->next=NULL;
        }
        else {
            ListNode* post= head2->next;
            head2->next = head->next;
            head->next= head->next ->next;
            head2->next->next=post;
        }
    }
}


