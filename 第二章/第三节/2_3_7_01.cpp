/**
 * 删除不带头节点的单链表中所有值为x的节点
*/

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node;

void print(node * head){
    node * p=head;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Remove(int x,node * head){
    /**
     * 删除其中所有值为x的节点
    */
    LNode * p ;
    if(head==NULL)
        return ;
    if(head->data==x){
        p=L;
        L=L->next ;
        delete p;
        remove(x,head);
    }
    else remove(x,head);
    
}


int main(){
    /**
    * 创建一个没有头节点的链表
    */
    node * head;
    int data;
    cin>>data;
    head = new node;
    head ->data =data;
    head->next=nullptr;
    node * tail =head;
    node *p;
    cin>>data;
    while(data!=-9999){
        p= new node;
        p->data=data;
        p->next=nullptr;
        tail->next=p;
        tail=tail->next;
        cin>>data;
    }
    print(head);

    return 0;


}