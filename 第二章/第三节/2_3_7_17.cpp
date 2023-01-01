//
// Created by Mac on 2023/1/1.
//
/*
 * 判断带头节点的循环双链表是否对称
 */
#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
    /*
     * 双向链表的节点
     */
    int data;
    struct Node *next;
    struct Node *pre;
}Node;

void CreateList(Node * head){
    head->next=head;
    int data;
    cin>>data;
    Node * p;
    p=head;
    while(data!=-9999){
        Node * q;
        q=new Node;
        q->data=data;
        q->next=head;
        q->pre = p;
        p->next = q;
        p=p->next;
        cin>>data;
    }
    p->next->pre = p;
}

void PrintList(Node *head){
    Node* p= head->next;
    while(p!=head){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int lengthOfLinklist(Node * head){
    int len=0;
    Node* p= head->next;
    while(p!=head){
        p=p->next;
        len++;
    }
    return len;
}

//void test(){
//    Node head;
//    CreateList(&head);
//    PrintList(&head);
//    cout<<lengthOfLinklist(&head)<<endl;
//}

bool isDuichen(Node* head){
    /*
     * 时间复杂度为 n/2,空间复杂度 O(1)
     */
    Node* p,* q;
    p=head->next,q=head->pre;
    while(!(p->next==q||p==q)){
        if(p->data!=q->data){
            return false;
        }
        p=p->next,q=q->pre;
    }
    return true;
}

int main(){
//    test();
    Node head;
    CreateList(&head);
    cout<<isDuichen(&head)<<endl;
    return 0;
}
