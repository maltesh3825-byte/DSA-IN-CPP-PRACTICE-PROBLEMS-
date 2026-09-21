//s imp using ll
#include<iostream>
using namespace std;
template <class T>
class Node{
public:
    T data;
    Node* next;
    Node(T val){
         data = val;
         next=NULL;
    }
};
template <class T>
class stack{
public:
    Node<T>* head;
    stack(){
        head =NULL;
    }
    void push(T val){
       
            Node<T>* newnode=new Node<T>(val);
            newnode->next=head;
            head=newnode;
        
    }
    void pop(){
        if(head!=NULL){
            Node<T>* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    T top(){
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
};
int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.isEmpty()){
        s.top();
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}