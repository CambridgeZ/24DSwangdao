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

//是否对称

bool isSymmetry(ListNode* head){
    ListNode* p,*q;
    p=head->next,q=head->pre;
    while(p!=q&&q->next!=p){
        if(p->val != q->val){
            return false;
        }
        else {
            p=p->next;
            q=q->pre;
        }
    }
    return true;
}
