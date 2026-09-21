//check for intersection
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
   
public:
     Node* head;
    Node *tail;
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
};
int getsize(Node* head){
    int size=0;
    while(head!=NULL){
        head=head->next;
        size++;
    }
    return size;
}
Node* getintersection(Node* headA,Node* headB){
    int m=getsize(headA);
    int n=getsize(headB);
    Node* t1=headA;
    Node* t2=headB;

    int diff=0;
    if(m>n){
        diff=m-n;
        for(int i=0;i<diff;i++){
            t1=t1->next;
        }
    }
    else{
        diff=n-m;
        for(int i=0;i<diff;i++){
            t2=t2->next;
        }
    }
    while(t1!=NULL && t2!=NULL &&t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    if(t1==NULL||t2==NULL){
        return NULL;
    }
    return t1;
}
int main(){
    List ll;
    List l2;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(6);
    ll.push_back(7);
    l2.push_back(4);
    l2.push_back(5);
    Node* temp=ll.head;
    Node* temp2=l2.head;
    while( temp!=NULL && temp->data!=6 ){
        temp=temp->next;
    }
    
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;

    Node* ans=getintersection(ll.head,l2.head);
    if(!ans){
        cout<<"no intersection\n";
    }
    else{
        cout<<"intersection point = "<<ans->data;
    }
    ll.print();
    l2.print();
    return 0;
   


}