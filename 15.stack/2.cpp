//stack implementation using ll
#include<iostream>
#include<list>
template <class T> 
class Stack{
public:
    list ll;
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    void top(){
        cout<<ll.head();
    }
    bool isEmpty(){
        return head==NULL;
    }
};
int main(){
    Stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(s.isEmpty){

    }
}