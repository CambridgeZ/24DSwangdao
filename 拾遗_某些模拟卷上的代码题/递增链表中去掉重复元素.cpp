//
// Created by Mac on 2023/12/15.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

void deleteRepeatELement(ListNode* head){
    ListNode* p=head->next;
    while(p->next){
        if(p->next->val==p->val){
            ListNode* q=p->next;
            p->next=q->next;
            delete q;
        }
        else {
            p=p->next;
        }
    }
}