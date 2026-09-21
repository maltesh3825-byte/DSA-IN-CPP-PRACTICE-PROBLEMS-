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
    ~Node(){
        if(next!=NULL){
            delete next;
            next=NULL;
        }
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
    void pop_front(){
        if(head=NULL){
            cout<<"LL is empty\n";
            return ;
        }
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        Node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;//not required as however we are going to delete temp's  next ie tail;
        delete tail;
        tail= temp;
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
    int findsize(){
        Node* temp=head;
        int size=0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        return size;

    }
    
    int removenth(int n){
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
    return 0;
}