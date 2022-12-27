//
// Created by Mac on 2022/12/27.
//
/**
 * 将单链表中的数字按照递增次序输出，并且每次输出一个之后就释放占用的空间（不可以用数组辅助）
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

void DeleteMinNode(Node *head){
    int min = 0x7fffffff;
    Node *p= head;
    Node *r= head->next;
    Node *minNode;
    Node *preMinNode;
    while(r){
        if(r->data<min){
            preMinNode=p;
            minNode=r;
            min=r->data;
        }
        r=r->next;
        p=p->next;
    }
    cout<<minNode->data<<" ";
    preMinNode->next=minNode->next;
    delete minNode;
}

void DeleteNodesAndPut(Node * head){
    /*
     * 遍历整个链表，每一次找到最小的值所在的节点，然后删除并且输出
     * 算法的时间复杂度为O(n^2)，效率比较低下
     */
    while(head->next){
        DeleteMinNode(head);
    }
}


int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    DeleteNodesAndPut(&head);
    return 0;
}
