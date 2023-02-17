//
// Created by Mac on 2023/2/17.
//
#include <iostream>
using namespace std;
//创建带头节点的单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//创建带头节点的单链表
void CreateList(LinkList &L,int n){
    L=new LNode;
    L->next=NULL;
    for(int i=0;i<n;i++){
        LNode *p=new LNode;
        cin>>p->data;
        p->next=L->next;
        L->next=p;
    }
}
//输出单链表
void printList(LinkList L){
    LNode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//选择排序
void SelectSort(LinkList L){
    LNode *p=L->next,* min;
    while (p->next){
        min=p;
        LNode * q;
        q=p;
        while(q){
            if(q->data<min->data)
                min=q;
            q=q->next;
        }
        swap(min->data,p->data);
        p=p->next;
    }
}

void test(){
    /*
     * 测试数据
     * 5    5 4 3 2 1
     */
    LinkList L;
    int n;
    cin>>n;
    CreateList(L,n);
    SelectSort(L);
    printList(L);
}

int main(){
    test();
    return 0;
}