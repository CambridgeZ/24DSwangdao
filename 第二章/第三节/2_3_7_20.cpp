//
// Created by Mac on 2023/1/1.
//

#include <iostream>
using namespace std;

typedef struct Node{
    /*
     * 双向链表的节点
     */
    int data;
    int freq;//初始化为0
    struct Node *next;
    struct Node *pre;
}Node;

class List_2_3_7_20 {
private:
    Node * head;
public:
    List_2_3_7_20(){
        head = new Node;
    }
    void CreateList();
    int lengthOfLinklist();
    void PrintList();
    void Locate(int x);
};

void  List_2_3_7_20::CreateList() {
    head->next=NULL;
    int data;
    cin>>data;
    Node * p;
    p=head;
    while(data!=-9999){
        /*
         * 创建双向链表
         */
        Node * q;
        q=new Node;
        q->freq=0;
        q->data=data;
        q->next=NULL;
        q->pre = p;
        p->next = q;
        p=p->next;
        cin>>data;
    }
}

int List_2_3_7_20::lengthOfLinklist() {
    int len=0;
    Node* p= head->next;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

void List_2_3_7_20::PrintList() {
    Node* p= head->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void List_2_3_7_20::Locate(int x) {
    Node *p = head->next;
    while (p->data != x&&p!=NULL) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "FAIL:The number doesn't exist!" << endl;
        return;
    }
    p->freq++;
    Node *q = p->pre;
    /*
     * 按照频率将找到的这个节点放到合适的地方
     */
    while (q->freq <= p->freq && q != head) {//从当前的位置向前，一直找到比这个节点的频率更大的数字或者到了头节点
        q = q->pre;
    }
    //移动节点
    if(p->next!=NULL){
        p->pre->next = p->next;
        p->next->pre = p->pre;

        p->next = q->next;
        q->next = p;
        p->pre = q;
        p->next->pre = p;
    }
    else{
        p->pre->next = p->next;
        p->next = q->next;
        q->next = p;
        p->pre = q;
        p->next->pre = p;
    }
}

int main(){
    List_2_3_7_20 list = List_2_3_7_20();
    list.CreateList();
    list.PrintList();
    int x;
    while(cin>>x){
        list.Locate(x);
        list.PrintList();
    }
    return 0;
}

