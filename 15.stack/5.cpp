//reverse a string using stack
#include<iostream>
#include<stack>
#include<string>
using namespace std;
string reversestr(string &str){
    string ans="";
    stack <char> s;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);

    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main(){
    string str="abcd";
    cout<<reversestr(str);
    return 0;
}
