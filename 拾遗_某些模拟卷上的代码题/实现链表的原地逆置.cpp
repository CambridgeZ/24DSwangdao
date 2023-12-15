//
// Created by Mac on 2023/12/15.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

ListNode* reverseList(ListNode* head){
    ListNode * L = new ListNode;

    ListNode* p= head->next;

    while(p){
        ListNode* q = p->next;
        p->next = L->next;
        L->next = p;
        p=q;
    }

    head->next = L ->next;
    return head;
}

void CreateList(ListNode* head,int n){
    ListNode* p = head;
    for(int i=0;i<n;i++){
        ListNode* q = new ListNode;
        cin>>q->val;
        /*
         * 输入数据：    1 2 3 4 5
         */
        q->next = NULL;
        p->next = q;
        p=q;
    }
}

//test
void test(){
    ListNode* head = new ListNode;
    CreateList(head,5);
    reverseList(head);
    ListNode* p = head->next;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
}

int main(){
    test();
    return 0;
}