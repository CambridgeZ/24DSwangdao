/*
    判断单链表中的字符是否对成
*/

#include <iostream>
#include <stack>

using namespace std;

typedef struct LNode{
    char data;
    struct LNode* next;
}LNode, * LinkList;

void CreateLinkList(LinkList head){
    char data;
    LinkList p;
    LinkList r=head;//尾节点
    cin>>data;
    while(data !='#'){
        p = new LNode;
        p->next = NULL;
        p->data = data;
        r->next = p;
        r=r->next;
        cin>>data;
    }
}

void Print(LinkList head){
    LinkList p=head->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

bool judge(LinkList head){
    stack<char> s;
    string sequence="";
    LinkList p=head->next;
    while(p){
        sequence+= p->data;
        s.push(p->data);
        p=p->next;
    }
    string sequence2="";
    while(!s.empty()){
        sequence2+=s.top();
        s.pop();
    }
    if(sequence2==sequence){
        return true;
    }
    else {
        return false;
    }
    cout<<endl;
}


int main(){
    LinkList head;
    head = new LNode;
    head->next = NULL;
    CreateLinkList(head);
    Print(head);
    if(judge(head)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}
