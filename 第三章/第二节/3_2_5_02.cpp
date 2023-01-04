//
// Created by Mac on 2023/1/4.
//
/*
 * 一个栈和一个队列，实现队列的逆转
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void initQueue(queue<int> &Q){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        Q.push(a);
    }
}

void printQueue(queue<int>Q){
    while(!Q.empty()){
        int x=Q.front();
        cout<<x<<" ";
        Q.pop();
    }
}

void fun(){
    queue<int> Q;
    initQueue(Q);
    stack<int> S;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        S.push(x);
    }
    while(!S.empty()){
        int x=S.top();
        Q.push(x);
        S.pop();
    }
    printQueue(Q);
}

int main(){
    fun();
}

