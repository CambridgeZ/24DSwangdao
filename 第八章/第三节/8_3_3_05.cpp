//
// Created by Mac on 2023/2/7.
//
/*
 * 设计一个时间复杂度为O(n)的算法，时色块按照荷兰国旗的顺序排列好
 */

#include <iostream>

#define RED 0
#define WHITE 1
#define BLUE 2

using namespace std;

void sort(int a[],int n){
    /*
     * 用一个不讲武德的方法，先遍历，记录其中白色的个数、红色的个数和蓝色的个数，然后从后向前，改成相应的色块数，不过这违背了排序的本质
     */
    int red=0,blue=0,white=0;
    for(int i=0;i<n;i++){
        if(a[i]==RED)
            red++;
        else if(a[i]==WHITE)
            white++;
        else
            blue++;
    }
    for(int i=n-1;i>=0;i--){
        if(blue>0){
            a[i]=BLUE;
            blue--;
        }
        else if(white>0){
            a[i]=WHITE;
            white--;
        }
        else{
            a[i]=RED;
            red--;
        }
    }
}

void Flag_Arrange(int a[],int n){
    /*
     * 设置两个指针，一个之前全是红色，一个之后全是蓝色,然后将所有的红色交换到red指针之前，将所有蓝色交换到blue指针之后
     */
    int red=0,blue=n-1;
    int i=0;
    while(red<blue){
        if(a[i]==RED){
            swap(a[i],a[red]);
            red++;
        }
        else if(a[i]==BLUE){
            swap(a[i],a[blue]);
            blue--;
        }
    }
}

int main(){

}
