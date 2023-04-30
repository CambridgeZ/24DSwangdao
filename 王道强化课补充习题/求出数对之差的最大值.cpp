//
// Created by Mac on 2023/4/30.
//

#include <iostream>

using namespace std;

int findTheGreatestBefore(int a[],int n){
    int maxBefore[n];
    maxBefore[1]=a[0];
    for(int i=1;i<n-1;i++){
        if(a[i]>maxBefore[i])
            maxBefore[i+1]=a[i];
        else
            maxBefore[i+1]=maxBefore[i];
    }
    int max=0;
    for(int i=1;i<n;i++){
        if(maxBefore[i]-a[i]>max)
            max=maxBefore[i]-a[i];
    }
    return max;
}

//test
/*
 *  2 4 1 16 7 5 11 9
 */

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << findTheGreatestBefore(a, n) << endl;
    return 0;
}