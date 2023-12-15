//
// Created by Mac on 2023/12/15.
//

#include <iostream>

using namespace std;

//双链表
struct ListNode{
    int val;
    ListNode* next;
    ListNode* pre;
};

//拼接两个循环链表

void lianjie(ListNode* head1,ListNode* head2){
    ListNode* p=head1->pre;
    p->next=head2->next;
    head2->next->pre=p;
    p=head2->pre;
    p->next=head1;
    head1->pre=p;
}