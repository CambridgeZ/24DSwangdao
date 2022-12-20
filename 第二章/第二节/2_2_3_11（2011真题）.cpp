/*
    求两个等长的序列的中位数
    1）
        1.分别找到两个序列的中位数，如果两个序列的中位数相同则意味着这个数字就是这两个序列的中位数
        2.如果两个序列的中位数不相同，
            比较两个中位数
            大的那个肯定比中位数大，小的那个肯定比中位数小
            那中位数肯定在大的那个序列的前半部分，在小的那个后半部分
            那么将大的那个的前面的序列拿出来研究，把小的那个的后半部分进行研究
            分别研究这两个序列的中位数，如果出现相同那就说明这个就是中位数了
        如果一直没有出现研究的两个序列的中位数相同，那么到最后这两个序列都只剩下一个数字，那么取比较大的那个
*/

#include <iostream>
#include <algorithm>
using namespace std;

int findTheMidNumberOfTwoSequences(int s1[], int s2[], int n){
    int low1=0, high1=n-1, low2=0, high2=n-1;
    int mid1,mid2;
    while(low1<=high1&&low2<=high2){
        mid1=(low1+high1)/2, mid2=(low2+high2)/2;
        if(s1[mid1]==s2[mid1]){
            return s1[mid1];
        }
        else if(s1[mid1]>s2[mid1]){//第一个序列的中位数比第二个序列的中位数大，则在这个时候研究第一个序列的前半部分和第二个序列的后半部分
            high1 = mid1-1;
            low2 = mid2+1;
        }
        else {
            low1 = mid1+1;
            high2 = mid2-1;
        }
    }
    // cout<<mid1<<" "<<mid2<<endl;
    return min(s1[mid1],s2[mid2]);//走到这一步，两个序列都各自只剩下一步一个数字在这个时候选择返回比较小的那个数字
}

int M_Search(int s1[], int s2[], int n){//答案给出的参考代码
    int low1=0, high1=n-1, low2=0, high2=n-1;
    int mid1,mid2;
    while(low1!=high1||low2!=high2){
        mid1=(low1+high1)/2, mid2=(low2+high2)/2;
        if(s1[mid1]==s2[mid1]){
            return s1[mid1];
        }
        else if(s1[mid1]>s2[mid1]){
            if((low1+high1)%2==0){//如果元素的个数为奇数
                low2 = mid2;
                high1 = mid1;
            }
            else {
                low2=mid2+1;//舍弃比较小的那个序列的前半部分的
                high1=mid1;
            }

        }
        else {//第一个的mid比较小的时候
            if((low1+high1)%2==0){//如果元素的个数为奇数
                low1 = mid1;
                high2 = mid2;
            }
            else {
                low1=mid1+1;//舍弃比较小的那个序列的前半部分的
                high2=mid2;
            }
        }
    }
    return min(s1[mid1],s2[mid2]);//走到这一步，两个序列都各自只剩下一步一个数字在这个时候选择返回比较小的那个数字
}

int main(){
    int n;
    cin>>n;
    int s1[n],s2[n];
    for(int i=0;i<n;i++){
        cin>> s1[i];
    }

    for(int i=0;i<n;i++){
        cin>> s2[i];
    }

    cout<< findTheMidNumberOfTwoSequences(s1,s2,n)<<endl;
    cout<< M_Search(s1,s2,n)<<endl;

    return 0;

}

/*
    时间复杂度O(log(n))
    空间复杂度O(1)
*/