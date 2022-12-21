#include <iostream>
#include <string>

using namespace std;

bool Judge(string s){
    int count = 0;
    for(int i=0; i<s.length();i++){
        if(s[i] == 'O')
            count--;
        if(s[i] == 'I')
            count++;
        if(count < 0)
            return false;
    }
    if(count == 0)
        return true;
    else 
        return false;
}

int main(){
    string s;
    cin>>s;
    if(Judge(s)==true)
        cout<<"True"<<endl;
    else 
        cout<<"False"<<endl;

    return 0;
}