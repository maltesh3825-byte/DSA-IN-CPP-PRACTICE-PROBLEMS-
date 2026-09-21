//valid paranthesis
#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch=='('||ch=='['||ch=='{'){
            s.push(ch);
        }
        else{
            //corner case of excess closing brace
            if(s.empty()){
                return false;
            }
            
            //match
            int top=s.top();
            if(ch==')'&&top=='('||ch==']'&&top=='['||ch=='}'&&top=='{'){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}
int main(){
    string s1="({[})";
    string s2="({})";
    cout<<isValid(s1)<<endl;
    cout<<isValid(s2);
    return 0;
}