//
// Created by Mac on 2023/12/15.
//
struct ListNode{
    int data;
    ListNode* next;
};

void deleteX(ListNode *L,int x){
    if(L->next->data==x){
        ListNode* p=L->next;
        L->next=L->next->next;
        delete p;
        deleteX(L->next,x);
    }
    else {
        deleteX(L->next,x);
    }
}

//非递归的方法

int getMinInLinkList(ListNode* head){
    int min= 0x7fffffff;
    ListNode* p=head->next;
    while(p){
        if(p->data<min){
            min=p->data;
        }
    }
    return min;
}

void DeleteMinX(ListNode* L){
    ListNode* p;
    p = L;

    int x= getMinInLinkList(L);

    while(p->next){
        if(p->next->data == x){
            ListNode * q=p->next;
            p->next=q->next;
            delete q;
        }
        else {
            p=p->next;
        }
    }
}


