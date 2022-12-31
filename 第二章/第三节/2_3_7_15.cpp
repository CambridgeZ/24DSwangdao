//
// Created by Mac on 2022/12/31.
//
/*
 * A,B 两个递增的链表，表示两个集合，求出两集合的交集放在A链表当中
 */
#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void CreateList(Node * head){
    head->next=nullptr;
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
    while(p){
        p=p->next;
        len++;
    }
    return len;
}

void findCommonElememt(Node* A,Node* B){
    /*
     * 设计思路
     * 对于设置一个指针，在A当中进行遍历
     * 另外还有一个在B当中进行遍历，如果向前找到了和这个A中的指针相同元素就保留，如果一直到了比这个还大的元素的地方，由于递增，就删掉
     */

    /*
     * 之前的设计存在一个问题，就是第二个表有可能比第一个表先遍历结束，因此应该选择的是同时对于两个表进行遍历,或者像我下面的amend一样修改
     */
    Node *p1 = A->next,*pre1=A;
    Node *p2 = B->next;
    while(p1) {
        if(p2) {
            while (p2->data < p1->data)
                p2 = p2->next;
            if (p2->data == p1->data) {
                p1 = p1->next;
                pre1 = pre1->next;
            } else {
                pre1->next = p1->next;
                delete p1;
                p1 = pre1->next;
            }
        }
        else{
            /*
             * 直接将A里面的节点山完
             */
            while(p1) {
                pre1->next = p1->next;
                delete p1;
                p1 = pre1->next;
            }
        }
    }

}

int main(){
    Node list1,list2;
    CreateList(&list1), CreateList(&list2);
    findCommonElememt(&list1,&list2);
    PrintList(&list1);
    return 0;
}
