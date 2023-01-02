//
// Created by Mac on 2023/1/2.
//
/*
 * 单链表有环指的是单链表的尾指针也指向了单链表中的某个节点，
 *
 * 判断单链表当中有没有环
 */
#include <iostream>
#include <vector>
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


void CreateCircle(Node* head){
    /*
     * 在单链表当中创造环
     */
    Node * p=NULL,*q=head;
    Node *r;
    r=head->next;
    while(r->next){
        r=r->next;
    }
    int i=3;
   while(i--)
        q=q->next;
    p=q;
    r->next=p;
}

bool isExistCircle(Node *head){
    /*
     * 判断链表当中是否有环
     * 如果这个链表当中有环的存在，那意味着这个链表当中有两个节点的next域指向的是同一个地址，一个朴素的想法就是将每个节点的next都存储起来，在遍历的过程当中进行比较
     * 如果在过程中发现某个节点的Next为NULL返回true，如果出现某个next的地址出现过，那就返回false
     * 这个算法时间复杂度为O(n^2)，空间复杂度为O(n)
     */
    Node* p;
    p=head;
    vector<Node*> nextAppeared;

    while(p->next!=NULL){
        if(std::find(nextAppeared.begin(), nextAppeared.end(),p->next)==end(nextAppeared)){
            nextAppeared.push_back(p->next);
            p=p->next;
        }
        else{
            return true;
        }
    }
    return false;
}

bool isExist(Node* head){
    /*
     * 王道给出的标准解答:
     * 设置两个指针，fast和slow，fast每次走两格子，slow指针每次走一个格子，
     * 如果有环那么fast一定先进入环,slow后进入环，在环当中两个指针一定会相遇
     * 如果没有环的话，那么fast一定会先遇到full
     */
    Node * fast=head,*slow = head;
    while(fast->next!=NULL&&fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
    /*
     * 时间复杂度为O(n)，空间复杂度为O(1)
     */
}

int main(){
    Node* head;
    head = new Node;
    CreateList(head);
    CreateCircle(head);
    cout<<isExistCircle(head)<<endl;
    return 0;
}