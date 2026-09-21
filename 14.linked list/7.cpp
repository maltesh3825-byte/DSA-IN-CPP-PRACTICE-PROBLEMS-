//delete nth node from end

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
    int findsize(){
        Node* temp=head;
        int size=0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        return size;

    }
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    int remnth(int n){
            int size=findsize();
            Node *prev=head;
            for(int i=1;i<(size-n);i++){
            prev=prev->next;
            }
            Node* todel=prev->next;
            prev->next=prev->next->next;
            delete todel;
        

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
    ll.remnth(2);
    ll.print();
    
    return 0;
}