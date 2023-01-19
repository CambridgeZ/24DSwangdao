//
// Created by Mac on 2023/1/18.
//
/*
 * 在查找的时候如果找到就和前面的一个元素
 */

#include<iostream>
#include <algorithm>
using namespace std;

/*****************************在顺序的前提下实现**********************************/

int search(int a[],int key,int n){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            if(i!=0){
                //和前驱节点交换
                swap(a[i-1],a[i]);
            }
            return i;
        }
    }
    return -1;
}

void test1(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    while(key!=-9999){

        cout<<search(a,key,n)<<endl;
        cin>>key;
    }
}


/******************************************************************************/

/*****************************在链式的前提下实现**********************************/
struct Node{
    int data;
    struct Node* next;
};

void CreateLinkList(Node* head){
    Node *p,*h;
    h=head;
    int n;
    cin>>n;
    while(n!=-9999){
        p=new Node;
        p->data=n;p->next=NULL;
        h->next=p;
        h=h->next;
        cin>>n;
    }
}

int search(Node * head,int key){
    Node *h,*p;
    h=head;p=head->next;
    int i=1;
    while(p){
        if(p->data==key){
            if(h!=head)
                swap(p->data,h->data);
            return i;
        }
        p=p->next,h=h->next;
        i++;
    }
    return -1;
}

void test2(){
    Node* head;
    head=new Node;
    head->next=NULL;
    CreateLinkList(head);
    int key;
    while(key!=-9999){
        cout<<search(head,key)<<endl;
        cin>>key;
    }
}

/******************************************************************************/




int main(){
    test1();
    test2();
}