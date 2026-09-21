//check palindrome using ll and stack
#include<iostream>
#include<list>
#include<stack>
using namespace std;
bool palindromeCheck(list<int> l){
    stack<int> s;
    int size=l.size();
    int midd=size/2;
    list<int> ::iterator temp=l.begin();
    list<int> ::iterator mid=l.begin();
    advance(mid,midd);
    while(temp!=mid){
        s.push(*temp);
        temp++;
    }
    if(size%2!=0){
        temp++;
    }
    while(temp!=l.end() && s.top()==*temp){
        s.pop();     
        temp++;  
    }
    if(!s.empty()){
        return false;
    }
    return true;
}
int main(){
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(1);
    cout<<palindromeCheck(l);
    return 0;
}