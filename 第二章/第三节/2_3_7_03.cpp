//
// Created by Mac on 2022/12/24.
//
/*
 * 将一个带头节点带链表反序输出
 */

#include <iostream>
#include <stack>
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

void ReversePrint(Node *head){//使用递归来解决问题
    if(head == nullptr)
        return ;
    else {
        ReversePrint(head->next);
        cout<<head->data<<" ";
    }
}

void ReversePrintByStack(Node *head){//使用栈来实现
    stack<int> Datas;
    Node * p=head->next;
    while(p){
        Datas.push(p->data);
        p=p->next;
    }
    while(!Datas.empty()){
        cout<<Datas.top()<<" ";
        Datas.pop();
    }
    cout<<endl;
    return ;
}

int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    ReversePrintByStack(&head);
    return 0;
}