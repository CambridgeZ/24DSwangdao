/**
 * 括号匹配
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatched(string s){
    int i=0;
    stack<char> st;
    while(s[i]){
        if(s[i]=='{'||s[i]=='('||s[i]=='[')
            st.push(s[i]);
        else if(s[i]==')'){
            if(st.top()=='(')
                st.pop();
            else return false;
        }
        else if(s[i]=='}'){
            if(st.top()=='{')
                st.pop();
            else return false;            
        }
        else if(s[i]==']'){
            if(st.top()=='[')
                st.pop();
            else return false;            
        }
        i++;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    if(isMatched(s))
        cout<<"True"<<endl;
    else 
        cout<<"False"<<endl;

    return 0;
}