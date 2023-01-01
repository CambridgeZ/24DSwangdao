//
// Created by Mac on 2023/1/1.
//

/*
 * 将两个循环单链表合成成为一个循环单链表
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

void MergeToCircleList(Node* list1,Node* list2){
    Node* p=list1->next;
    while(p->next!=list1){
        p=p->next;
    }
    p->next=list2->next;
    while(p->next!=list2)
        p=p->next;
    p->next=list1;
}

int main(){
    Node *list1,*list2;
    list1= new Node,list2 = new Node;
    CreateList(list1), CreateList(list2);
    MergeToCircleList(list1,list2);
    PrintList(list1);
    return 0;
}
