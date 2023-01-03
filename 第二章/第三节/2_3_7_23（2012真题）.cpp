//
// Created by Mac on 2023/1/3.
//
/*
 * 两个链表具有相同的后缀，识别相同后缀从什么时候开始
 */
#include <iostream>
using namespace std;

typedef struct Node{
    char data;
    struct Node *next;
}Node;

void CreateList(Node * head){
    char data;
    cin>>data;
    Node * p;
    p=head;
    while(data!='#'){
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
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

void CreateListWithSameTails(Node* list1,Node* list2,Node* tails){
    Node * r1=list1,* r2=list2;
    while(r1->next)
        r1=r1->next;
    while (r2->next)
        r2=r2->next;
    r1->next=tails->next;
    r2->next=tails->next;
}

Node * findTheBeginningOfTheTail(Node* head1,Node* head2){
    /*
     * 先求出两个链表的长度，然后比较长度之差为dis，则让比较长的一个链表的指针向前移动dis个单位
     * 随后两个指针开始同时移动，当指向两个链表的指针相同的时候则说明到达了相同的尾部的开始
     *
     * 时间复杂度为O(m+n)，具体来说应该为--2(m+n),在空间复杂度上为O(1)
     */
    int len1= lengthOfLinklist(head1),len2 = lengthOfLinklist(head2);
    Node  *p1=head1,*p2=head2;
    int dis=len1-len2;
    if(dis<0){//第一个链表比较短，将第二个链表的指针现行向后移动
        while(dis){
            p2=p2->next;
            dis++;
        }
    }
    else{//第二个链表比较短，将第一个先向后移动
        while(dis){
            p1=p1->next;
            dis--;
        }
    }
    while(p1!=p2&&p1&&p2){
        p1=p1->next;
        p2=p2->next;
    }
    if(p1=p2)
        return p1;
    else{
        cout<<"ERROR"<<endl;
        return nullptr;
    }
}

int main(){
    Node *head1,*head2,*tail;
    head1=new Node,head2=new Node,tail= new Node;
    CreateList(head1), CreateList(head2), CreateList(tail);
    CreateListWithSameTails(head1,head2,tail);
    Node* beginNode= findTheBeginningOfTheTail(head1,head2);
    if(beginNode!=nullptr){
        cout<<beginNode->data<<endl;
    }
    return 0;
}
