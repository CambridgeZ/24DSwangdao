//
// Created by Mac on 2023/1/2.
//

/*
 * 查找一个链表的倒数第k个节点
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

bool findTheLastK(Node* head,int k){
    /*
     * 设置两个指针p,q,在开始令q指向头节点,p则指向后面第k个节点，如果在这个过程中发现q后面k个节点则直接返回0
     * 两个指针同时向后移动，在p为NULL的时候，这个时候q指向的就是倒数第k个节点
     * 这个算法的时间复杂度为O(n),空间复杂度为O(1)
     */
    Node *p,*q;
    p=head;
    q=p;
    while(k--){
        if(p)
            p=p->next;
        else
            return false;
    }
    while(p){
        q=q->next;
        p=p->next;
    }
    cout<<q->data<<endl;
    return true;
}

int main(){
    Node* head;
    head = new Node;
    CreateList(head);
    int k;
    cin>>k;
    findTheLastK(head,k);
    return 0;
}
