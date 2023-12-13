//
// Created by Mac on 2023/12/13.
//

/*
 * 找出连续相同数字的和为s的最长子数组的长度
 */

#include <iostream>

using namespace std;

int findTheLengestSameNumberWithSumS(int a[],int n,int s){
    int max_length=0;
    int begin=0,end=0;
    int sum_now=a[0];
    while(begin <=n-1 || end <=n-1){
        end++;
        if(a[end]==a[end-1]){//如果这个数字和前面的数字依然相同
            sum_now+=a[end];//加上当前的数字
        }
        else {//如果当前的数字和前面不同，说明是一组新的连续的数字
            begin=end;
            sum_now=a[begin];
        }
        if(sum_now==s){
            int length_now = end-begin+1;
            if(length_now> max_length){
                max_length= length_now;
            }
            //由于相同了，后面再加必然不可能了
            begin=end+1,end=end+1;
        }
        else if(sum_now<s){
            while(end<n-1&&a[end]==a[end+1]){
                end++;
                sum_now+=a[end];
            }
        }
        else if(sum_now>s){
            while(begin<=end && sum_now>s){
                sum_now=sum_now-a[begin];
                begin++;
            }
        }

        if(sum_now==s){
            int length_now = end-begin+1;
            if(length_now> max_length){
                max_length= length_now;
            }
            //由于相同了，后面再加必然不可能了
            begin=end+1,end=end+1;
        }

    }

    return max_length;
}

//test
/*
     * 测试数据：
     * 8 3  1 1 2 1 1 1 2 1
     *
*/
int main(){
    int n,s;
    cin>>n>>s;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<findTheLengestSameNumberWithSumS(a,n,s);
    return 0;
}
