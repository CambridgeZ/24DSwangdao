/**
 * 找出数组中没有出现的最小正整数
 * 
 * 我的算法：
 *      我的算法还是基于排序的，因此时间复杂度还是O(nlogn),让我过一会试试能不能找出O(n)的算法，至于空间复杂度还是O(1)
 *      先是扫描数组，将数组中的k个正整数保存到数组的前k个位置，然后对于这前k个位置上的正整数进行排序
 *      在排序完成之后扫描这个数组，如果这个数组第一个出现i!= 这个位置保存的元素的就是这个第一次缺少的，对于特殊情况，如果扫描结束了还是没有发现就直接返回k
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int fun(int a[],int n){
    int k=0;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            a[k++]=a[i];
        }
    }

    sort(a,a+k);
    for(int i=0;i<k;i++){
        if(i-a[i]!=-1)
            return i+1;
    }
    return k+1;
}

/**
 * 答案给出的算法
 * 其实我也想到了这个算法，但是处于对于空间利用上的顾虑没有下手，经过答案提示，这里只是要求是时间上尽可能的高效，因此在这个题目里面是可以使用用空间换时间的方法
 * 
 * 对于标答中给出的方法，如果想要这个使用的空间更加节省的话其实是可以使用bit运算来代替直接申请数组的，但是太麻烦了并且在考研里面也没有必要这样做
*/
int FindMissMin(int a[],int n){
    bool b[n+1];
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        if(a[i]>0&&a[i]<=n){
            b[i+1] = 1; 
        }
    }
    for(int i=0;i<=n;i++){
        if(!b[i])
            return i+1;
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<fun(a,n)<<endl;

    return 0;

}