//
// Created by Mac on 2023/1/4.
//

/*
 * 利用两个栈来模拟一个队列
 */
#include <iostream>
#include <stack>

using namespace std;

class queue{
private:
    stack<int> S1,S2;
public:
    void Enqueue(int x);//入队列
    void Dequeue(int &x);//出队列
    bool QueueEmpty();//判断队列是否为空
};

void queue::Enqueue(int x) {
    if(S1.empty())
        return ;
    S1.push(x);
}

void queue::Dequeue(int &x) {
    while(!S1.empty()){
        S2.push(S1.top());
        S1.pop();
    }
    x=S1.top();
    S1.pop();
    while(!S2.empty()){
        S1.push(S2.top());
        S2.pop();
    }
}

bool queue::QueueEmpty() {
    return S1.empty();
}

int main(){

}
