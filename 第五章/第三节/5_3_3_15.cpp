//
// Created by Mac on 2023/1/11.
//
/*
 * 有一个满二叉树，已经知道这个二叉树的先序序列序列pre，求后序序列post
 */

#include <iostream>
#include <string>

using namespace std;

string getThePostAccordingToTheLast(string pre,int begin,int end){
    string ans="";
    if(begin==end){
        ans+=pre[end];
        return ans;
    }
    /*
     * 分而治之的思想
     */
    ans=getThePostAccordingToTheLast(pre,begin+1,begin+(end-begin+1)/2)+ getThePostAccordingToTheLast(pre,begin+(end-begin+1)/2+1,end)+pre[begin];

    return ans;

}

int main(){
    cout<<getThePostAccordingToTheLast("1234567",0,6)<<endl;
    return 0;
}
