#include <iostream>
#define MAX_SIZE 10

using namespace std;

class sharedStack{
private:
	int data[MAX_SIZE];
	int top1=-1,top2=MAX_SIZE;
public:
	bool isFull(){
		if(top2-top1==1){
			return true;
		}
		else 
			return false;
	}
	
	bool isEmplty1(){
		if(top1==-1)
			return true;
		else 
			return false;
	}
	
	bool isEmpty2(){
		if(top2==MAX_SIZE)
			return true;
		else 
			return false;
	}
	
	bool Pop1(int &e){
		if(isEmplty1()){
			return false;
		}
		else{
			e=data[top1--];
			return true;
		}
	}
	
	bool Pop2(int &e){
		if(isEmpty2()){
			return false;
		}
		else{
			e=data[top2++];
			return true;
		}
	}
	
	bool Push1(int e){
		if(isFull()){
			return false;
		}
		else {
			data[++top1]=e;
			return true;
		}
	}
	
	bool Push2(int e){
		if(isFull()){
			return false;
		}
		else {
			data[--top2]=e;
			return true;
		}
	}
	
};

int main(int argc, char *argv[]) {
	sharedStack s;
	
}