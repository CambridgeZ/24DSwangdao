/**
 * 删除带头节点的链表中的所有值为x的节点
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

void DeleteNode(Node *head,int x){
    Node *p= head;
    Node *r= head->next;
    while(r){
        if(r->data==x){
            p->next=r->next;
            delete r;
            r=p->next;
        }
        else {
            r=r->next;
            p=p->next;
        }
    }
}

int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    int x;
    cin>>x;
    DeleteNode(&head,x);
    PrintList(&head);

    return 0;
}