//delete a cycle
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
void removeCycle(Node *head){
    Node* slow;
    Node* fast;
    slow = fast = head;
    bool isbool=false;

    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"cycle exists\n";
            isbool=true;
        }
    }
    if(!false){
        cout<<"cycle  not  exists\n";
        return ;
    }
    slow=head;
    if(slow==fast){
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else{
        Node* prev=fast;
        while(fast!=slow){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=NULL;
    }
    

}
int main(){
    List ll;
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    //ll.tail->next=ll.head;
    removeCycle(ll.head);
    ll.print();
    return 0;
}
