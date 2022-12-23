/**
 * 三个生序排列的序列，求所组成的三元组的可能的最小距离
 * 
*/

#include <iostream>
#include <cmath>
using namespace std;

int findMinDistance(int a[],int n,int b[],int m,int c[],int k){
    /**
     * 我的代码，现在看来应该是有问题的，只跑对了书上的一组数据，我自己写的几组数据都错了
    */
    int RealminDistance=0x3fffffff;
    int index[3];
    int indexNeedToMove=0;
    int index1=-1,index2=-1,index3=-1;

    for(int i=0;i<3;i++){
        int rindex1=-1,rindex2=-1,rindex3=-1;
        index[0]=0,index[1]=0,index[2]=0;
        indexNeedToMove=i;
        int minDistance=0x3fffffff;
        while(index[0]<n&&index[1]<m&&index[2]<k){
            int distance=abs(a[index[0]]-b[index[1]])+abs(a[index[0]]-c[index[2]])+abs(b[index[1]]-c[index[2]]);
            if(distance<=minDistance){
                minDistance=distance;
                index[indexNeedToMove]++;
                index1=index[0],index2=index[1],index3=index[2];
            }
            else {
                index[indexNeedToMove]--;
                indexNeedToMove=(indexNeedToMove+1)%3;
            }
        }
        if(minDistance<RealminDistance){
            RealminDistance=minDistance;
            index1=rindex1,index2=rindex2,index3=rindex3;
        }
    }
    cout<<index1<<" "<<index2<<" "<<index3<<endl;
    return RealminDistance;
}

int findMinOfTrip(int a[],int n,int b[],int m,int c[],int k){
    int i=0,j=0,k=0,D_min=0x7fffffff;
    while(i<n&&j<m&&k<p&&D_min>0){
        D=abs(a[i]-b[j])+abs(a[i]-c[k])+abs(b[j]-c[k]);
        if(D<D_min){
            D_min=D;
        }
        if(a[i]<=b[j]&&a[i]<=c[k]) i++;
        else if(a[i]>=b[j]&&c[k]>=b[j] j++;
        else k++;
    }
    return D_min;
}

int main(){
    int n,m,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    cin>>k;
    int c[k];
    for(int i=0;i<k;i++){
        cin>>c[i];
    }

    cout<<findMinDistance(a,n,b,m,c,k)<<endl;
    return 0;


}