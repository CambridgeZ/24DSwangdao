#include <iostream>

using namespace std;

//review QuickSort

int Partition(int a[],int begin,int end){
	int x=a[begin];
	while(begin<end){
		while(begin<end && a[end]>=a[begin])
			end--;
		a[begin] = a[end];
		while(begin<end && a[end] >= a[begin])
			begin++;
		a[end] = a[begin];
	}
	a[begin]=x;
	return begin;
}

void QuickSort(int a[],int begin,int end){
	if(begin<end){
		int pivot=Partition(a,begin,end);
		QuickSort(a, begin, pivot-1);
		QuickSort(a, pivot+1, end);
	}
}

void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<< a[i] <<" ";
	}
	cout<<endl;
}

void test(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	QuickSort(a, 0, n-1);
	show(a, n);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}