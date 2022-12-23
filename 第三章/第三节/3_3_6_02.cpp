#include <iostream>
#include <stack>
#include <string>

using namespace std;

string ChangeSequence(string &s){
    stack<char> st;
    int i=0;
    string result="";
    while(s[i]){
        if(s[i]=='H'){
            st.push(s[i]);
        }
        else {
            st.push(s[i]);
            result += st.top();
            st.pop();
        }
        i++;
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;

}

int main(){
    string s;
    cin>>s;
    cout<<ChangeSequence(s)<<endl;
    return 0;
}