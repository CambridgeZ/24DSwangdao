//
// Created by Mac on 2023/1/1.
//
/*
 * 对于带头节点的循环单链表，找出循环单链表当中值最小的节点输出并且将其删除，直到这个单链表当中只剩下头节点位置
 * 然后再删除头节点
 */

#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
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
        p->next = q;
        p=p->next;
        cin>>data;
    }
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

void test(){
    /*
     * 测试循环单链表单性能
     */
    Node * head;
    head = new Node;
    CreateList(head);
    PrintList(head);
    cout<<lengthOfLinklist(head)<<endl;
}

void deleteTheMinNode(Node* head);

void deleteTheNodesBySequence(Node* head){
    /*
     * 时间复杂度为O(n^2)，效率比较低效
     */
    while(head->next!=head){
        deleteTheMinNode(head);
    }
    delete head;
}

void deleteTheMinNode(Node * head){
    int min=0x3fffffff;
    Node* pre,*p,*min_Node,*pre_min_Node;
    p=head->next;
    pre=head;
    while(p!=head){
        if(p->data<min){
            min=p->data;
            min_Node=p,pre_min_Node=pre;
        }
        p=p->next,pre=pre->next;
    }
    cout<<min_Node->data<<" ";
    pre_min_Node->next=min_Node->next;
    delete min_Node;
}

int main(){
    Node * head;
    head = new Node;
    CreateList(head);
    deleteTheNodesBySequence(head);
    return 0;
}
