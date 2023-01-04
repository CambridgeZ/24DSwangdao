//
// Created by Mac on 2023/1/4.
//

/*
 * 希望循环队列中所有的元素都能够没利用,设置一个tag
 *
 * 王道的思路比我更直接一点，直接在出队的时候一律设为0,入队的时候一律设为1
 * 但是如果考虑到求长度等操作还是我这个更好
 */
#include <iostream>
#include <cstring>
#define MAXSIZE 5

using namespace std;
class queue{
private:
    int tag=0;
    int front=0,back=0;
    int data[MAXSIZE];
public:
    queue();
    bool push(int x);
    bool pop(int &x);
    int length();
    bool isEmpty();
    bool isFull();
    void print();
};

bool queue::push(int x) {
    if(isFull()){
        return false;
    }
    data[back]=x;
    back++;
    if(back>=MAXSIZE){
        tag++;
        back=back%MAXSIZE;
    }
    return true;
}

bool queue::pop(int &x) {
    if(isEmpty())
        return false;
    x=data[front];
    data[front]=0;
    front++;
    if(front>=MAXSIZE){
        tag--;
        front=front%MAXSIZE;
    }
    return true;
}

bool queue::isEmpty() {
    if(tag==0&&front==back){
        return true;
    }
    else{
        return false;
    }
}

int queue::length() {
    return back-front+tag*MAXSIZE;
}

bool queue::isFull() {
    if(tag==1&&back==front)
        return true;
    else
        return false;
}

void queue::print() {
    int i=front;
    if(tag==1){
        cout<<data[front]<<" ";
        i++;
        i=i%MAXSIZE;
    }
    while(i!=back){
        cout<<data[i]<<" ";
        i++;
        i=i%MAXSIZE;
    }
    cout<<endl;
}

queue::queue() {
    ::memset(data,0,sizeof (data));
}

int main(){
    queue Q;
    int x;
    Q.push(1);
    Q.pop(x),cout<<x<<endl;
    Q.push(2),Q.push(3),Q.push(4);
    Q.print();
    Q.pop(x);
    Q.push(5),Q.push(6),Q.push(7);
    Q.print();
    Q.pop(x),Q.pop(x);
    Q.print();
    cout<<Q.length()<<endl;
    return 0;
}
