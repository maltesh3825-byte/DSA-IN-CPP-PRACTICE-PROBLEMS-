//duplicate paranthesis
#include<iostream>
#include<stack>
using namespace std;
bool dup(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch!=')'){//opening brac
            s.push(str[i]);
        }
        //closing brac
        else{
            if(s.top()=='('){
                return true;
            }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }
    return 0;

}
int main(){
    string s1="((a+b))";
    string s2="((a+b)+(c+d))";
    cout<<dup(s1)<<endl;
    cout<<dup(s2);
    return 0;
}