//insert in middle of LL
#include<iostream>
using namespace std;
//intro to linked list
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class List{
    Node* head;
    Node *tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node * newNode=new Node(val);
    
    if(head==NULL){
        head=tail=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;

    }
    }
    void push_back(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    
    }
    void print(){
          Node* temp=head;
           while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    void insert(int val,int pos){
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        //now temp is at pos -1
        newNode->next=temp->next;
        temp->next=newNode;
    }
};
int main(){
    List ll;
    ll.push_back(2);
    ll.push_back(65);
    ll.push_back(78);
    ll.push_back(98);
    ll.push_back(200);
    ll.print();
    ll.insert(500,3);
    ll.print();
    return 0;
}