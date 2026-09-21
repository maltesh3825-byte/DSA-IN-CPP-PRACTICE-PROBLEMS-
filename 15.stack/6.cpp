//reverse a stack using recursion
#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return ;
    }
    int temp=s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
    return;
}
void Reverse(stack <int> &s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    Reverse(s);
    pushAtBottom(s,temp);
}
void print (stack<int> s){
        while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout<<"\n";
}
int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    print(s);
    Reverse(s);
    print(s);
    return 0;
}

