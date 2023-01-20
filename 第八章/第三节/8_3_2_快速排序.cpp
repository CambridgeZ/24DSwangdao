//
// Created by Mac on 2023/1/20.
//
#include <iostream>
using namespace std;

int Partition(int a[],int low,int high){
    //对于数列进行划分
    int pivot=a[low];
    while(low<high){
        /*
         * 在这样的一个整个过程当中,low表示的都是枢轴本应该所在位置的左边的位置，而high始终都是指的枢轴本应该所在的位置右边的位置
         * 当这样的两个指针碰面的时候就意味着两个走到的位置就应该是枢轴所应该在的正确的位置
         */
        while(low<high&&a[high]>=pivot){
            high--;
        }
        a[low]=a[high];//将比枢轴小的移动到枢轴到左边,
        while(low<high&&a[low]<=pivot)
            low++;
        a[high]=a[low];//将比枢轴大的移动到枢轴右边的某个位置
    }
    //将枢轴放置到枢轴本身应该存放的位置上面
    a[low]=pivot;
    return low;//返回枢轴最终的位置
}

void QuickSort(int a[],int low,int high){
    if(low<high){
        int pivotpos= Partition(a,low,high);
        //
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
}

void printArray(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    QuickSort(a,0,n-1);
    printArray(a,n);
    return 0;
}