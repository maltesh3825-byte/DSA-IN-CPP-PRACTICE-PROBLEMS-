#include<iostream>
using namespace std;
class Node{
public:
    Node* next;
    Node* prev;
    int data;
    Node(int val){
        data = val;
        prev=next=NULL;
    }
};
class Doublyll{
public:
    Node* head;
    Node* tail;
    Doublyll(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode; 
            head=newNode;
        }
    }
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
    }
    
};
int main(){
    Doublyll dl;
    dl.push_front(4);
    dl.push_front(3);
    dl.push_front(2);
    dl.push_front(1);
    dl.print();

}