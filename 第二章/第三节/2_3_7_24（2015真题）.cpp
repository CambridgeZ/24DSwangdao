//
// Created by Mac on 2023/1/3.
//
/*
 * 单链表保存m个整数，并且其中data的绝对值小于等于n
 * 设计一个尽可能高效的算法，把其中绝对值重复的节点，只保留第一次出现的节点，其他的节点都删除
 */

#include <iostream>
#include <cmath>
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

void deleteMultiNumber(Node* head,int m){
    /*
     * 设计思路：
     * 由于题目给出了｜data｜<n的条件，那么说明m个节点当中存放的数字的不同的绝对值种类一定是小于m的,而且这些数字一定分布在0-m这个范围内
     * 于是bool类型数组 NumberAppeard[m+1]，并在开始时将整个数组的值全部设置为false
     * 遍历链表，对于每个节点，令变量posi=abs(p->data)，如NumberAppeard[posi]=true则删除当前的节点，否则则将NumberAppeard[posi]设为true
     *
     * 空间复杂度为O(m),时间复杂度为O(m)
     */
    bool NumberAppeard[m+1];
    ::memset(NumberAppeard,0,sizeof (NumberAppeard));
    Node *p=head->next,*pre=head;
    while(p){
        int posi=abs(p->data);
        if(NumberAppeard[posi]==false){
            NumberAppeard[posi]= true;
            p=p->next;
            pre=pre->next;
        }
        else{
            pre->next=p->next;
            delete p;
            p=pre->next;
        }
    }
}

int main(){
    Node * head;
    head = new Node;
    CreateList(head);
    int m= lengthOfLinklist(head);
    deleteMultiNumber(head,m);
    PrintList(head);
    return 0;
}
