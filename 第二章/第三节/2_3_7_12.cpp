//
// Created by Mac on 2022/12/27.
//
/*
 * 删除单链表当中重复的元素（加强版：去掉了原来限制的有序的条件，顺便综合了一下哈希表的用法）
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

int lengthOfLinklist(Node * head){
    int len=0;
    Node* p= head->next;
    while(p){
        p=p->next;
        len++;
    }
    return len;
}

/*
 * 采用哈希表存储其中已经出现的值，在进行求值的过程当中对于对于遍历的每一个节点的值在哈希表中进行查找，如果没有找到就将这个值写入哈希表，如果找到就删除这个节点
 * 时间复杂度为O(n)
 */
bool isExistInhash(int hash[],int val,int length){
    int position = val%length;
    int dis=0;
    while(true){
        int posi;
        if(dis%2==1){
            posi=position+dis;
        }
        else {
            posi=position-dis;
        }
        if(hash[posi]==0){
            hash[posi]=val;
            return false;
        }
        if(hash[posi]==val){
            return true;
        }
        dis++;
    }
}

void deleteRepeatedNodes(Node* head){
    int length= lengthOfLinklist(head);
    int hash[length];//定义哈希表
    std::memset(hash,0,sizeof (hash));
    Node * p= head->next;
    Node * pre =head;
    while(p){
        if(isExistInhash(hash,p->data,length)){
            pre->next=p->next;
            delete p;
            p=pre->next;
        }
        else {
            p=p->next;
            pre=pre->next;
        }
    }
}

int main(){
    Node head;
    CreateList(&head);
    PrintList(&head);
    deleteRepeatedNodes(&head);
    PrintList(&head);
}