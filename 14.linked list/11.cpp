//zig zag ll
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
    ~Node(){
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
    
};
class List{
    
public:
    Node* head;
    Node *tail;
    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
        delete head;
        head = NULL;
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
};
Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            //updataion for next itr
            prev=curr;
            curr=next;
        }
        return prev;//prev will have become curr ie head;
    }
Node* splitAtMid(Node* head){
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    return slow;

}
Node* zigzag(Node* head){
    Node* righthead=splitAtMid(head);
    Node* rightheadrev=reverse(righthead);
    Node* left=head;
    Node* right=rightheadrev;
    
    //alternate merge
    while(left!=NULL&&right!=NULL){
        
    }
}