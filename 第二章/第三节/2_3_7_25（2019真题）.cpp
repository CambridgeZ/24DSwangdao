//
// Created by Mac on 2023/1/3.
//
/*
 * 设线性表为L(a1,a2,a3,....an-1,an),采用带有头节点的单链表进行存储
 * 设计一个空间复杂度为O(1)，时间上尽可能高效的算法，将这个链表转换为L(a1,an,a2,an-1....)
 */
#include <iostream>
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
int lengthOfLinklist(Node * head){
    int len=0;
    Node* p= head->next;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

Node* Reverse(Node* head){
    //逆置链表
    Node* newHead;
    newHead= new Node;
    *newHead=*head;newHead->next=NULL;
    Node* p=head->next;
    while(p){
        head->next=p->next;
        p->next=newHead->next;
        newHead->next=p;
        p=head->next;
    }
    return newHead;
}

Node* operateTheLinkList(Node * head){
    /*
     * 求链表的长度以及找中间节点用掉的时间为 1.5n,逆转链表用去的时间为O(n),合并用掉的时间为O(n)
     * 首先求出长度，找到根据长度找到中间节点，将后半部分逆转，然后合并
     *
     * （积累标准答案的找中间节点的方法，设置两个节点，一个每次向前移动2步,一个每次向前移动1步）
     */
    Node * newHead,* lastNodes;
    newHead= new Node;
    newHead->next=NULL;
    int len = lengthOfLinklist(head);
    int back=len/2;
    lastNodes=head;
    while(back--){
        lastNodes=lastNodes->next;
    }
    Node* backHead;
    backHead= new Node;

    if(len%2==0){
        backHead->next=lastNodes->next;
        lastNodes->next=NULL;
    }
    else{
        backHead->next=lastNodes->next->next;
        lastNodes->next->next=NULL;
    }

    backHead= Reverse(backHead);
    /*
     * 检测需要合并的两部分有没有问题
     */
//    PrintList(backHead);
//    PrintList(head);
    /****************************************/

    Node *p=head->next,*q=backHead->next;
    Node *r=newHead;
    int count=1;
    while(p&&q){
        if(count%2==1){
            r->next=p;
            r=r->next;
            p=p->next;
            r->next=NULL;
        }
        else{
            r->next=q;
            r=r->next;
            q=q->next;
            r->next=NULL;
        }
        count++;
    }
    if(p){
        r->next=p;
        p->next=NULL;
        r=r->next;
    }
    if(q){
        r->next=q;
        q->next=NULL;
        r=r->next;
    }
    return newHead;
}

int main(){
    Node* head;
    head= new Node;
    CreateList(head);
    head=operateTheLinkList(head);
    PrintList(head);
    return 0;
}

