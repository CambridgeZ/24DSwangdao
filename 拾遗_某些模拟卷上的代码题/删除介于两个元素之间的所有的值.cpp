//
// Created by Mac on 2023/12/15.
//

struct ListNode{
    int data;
    ListNode* next;
};

void deleteNumberBetweenXY(ListNode* head,int x,int y){
    ListNode* p=head;
    while(p->next){
        if(p->next->data>x && p->next->data<y){
            ListNode* q=p->next;
            p->next=q->next;
            delete q;
        }
        else {
            p=p->next;
        }
    }
}

