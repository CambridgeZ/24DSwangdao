//
// Created by Mac on 2023/1/1.
//
/*
 * 判断一个序列是不是另一个序列的连续子序列
 * 两个序列都是存放在单链表当中
 */

#include <iostream>
#include <string>
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

bool JudgeIsSubeString(Node* list1,Node *list2){
    /*
     * 将字符放入字符串当中，然后用模式匹配算法解决
     * 采用时间换取空间的做法
     */
    Node* p1=list1->next, *p2=list2->next;
    string s1="",s2="";
    while(p1){
        s1+='0'+p1->data;
        p1=p1->next;
    }
    while(p2){
        s2+='0'+p2->data;
        p2=p2->next;
    }
    if(s1.find(s2)!=string::npos)
        return true;
    else
        return false;
}

bool judgeIsSubString(Node* list1,Node *list2){
    /*
     * 复现书上给出来的思路
     * 类似于模式匹配的朴素方法的实现思路
     */
    Node *p1,*p2;
    p2=list2->next;
    p1=list1->next;
    while(p1&&p2){
        if(p1->data==p2->data){
            p2=p2->next;
            Node* p=p1->next;
            while(p2&&p&&p2->data==p->data){
                p=p->next,p2=p2->next;
            }
            if(p2==nullptr)
                return true;
            else{
                p2=list2->next;
                p1=p1->next;
            }
        }else{
            p1=p1->next;
        }
    }
    return false;
}

int main(){
    Node list1,list2;
    CreateList(&list1), CreateList(&list2);
    if(judgeIsSubString(&list1,&list2)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}


