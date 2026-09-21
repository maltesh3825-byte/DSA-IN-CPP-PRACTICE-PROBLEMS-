//builing hash table with insert,search and remove
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Node{
public:
    int val;
    string key;
    Node* next;

    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class Hashtable{
int totsize;
int currsize;
Node** table;
public:
    int Hashfunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx+=(key[i]*key[i])%totsize;
        }
        return idx%totsize;
    }

    void rehash(){
        int oldsize=totsize;
        totsize=2*oldsize;
        currsize=0;
        Node** oldtable=table;
        table= new Node*[totsize];
        for(int i=0;i<totsize;i++){
            table[i]=NULL;
        }

        for(int i=0;i<oldsize;i++){
            Node * temp= oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete [] oldtable;

    }

    Hashtable(int size=5){
        totsize=size;
        currsize=0;

        table=new Node*[totsize];
        for(int i=0;i<totsize;i++){
            table[i]=NULL;
        }
    }

    void insert(string key,int val){
        int idx=Hashfunction(key);
        Node* newnode=new Node(key,val);
        
        newnode->next=table[idx];
        table[idx]=newnode;
        currsize++;

        double lambda=currsize/(double) totsize;
        
        if(lambda>1){
            rehash();
        }
    
    }
    bool exists(string key){
        int idx=Hashfunction(key);
        Node* temp= table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    int search(string key){
        int idx=Hashfunction(key);
        Node* temp= table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }

    void remove(string key){
        
        int idx=Hashfunction(key);
        Node* temp= table[idx];
        Node* prev=temp;
        while(temp!=NULL){
           if(temp->key==key){
             if(prev==temp){
                table[idx]=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            temp->next=NULL;
            delete temp;
            break;
           }
           prev=temp;
           temp=temp->next;
        }
        
    }

    void print(){
        for(int i=0;i<totsize;i++){
            cout<<"idx"<<i<<"->";
            Node * temp =table[i];
            while(temp!=NULL){
                cout<<temp->key<<","<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    Hashtable ht;
    ht.insert("india",260);
    ht.insert("china",200);
    ht.insert("us",50);
    ht.insert("nepal",10);
    ht.insert("uk",26);
    // if(ht.exists("india")){
    //     cout<<"indias population (in cr) : "<<ht.search("india");
    // }
    ht.print();
    cout<<"----------------"<<endl;
    ht.remove("china");
    ht.remove("india");
    ht.remove("uk");
    ht.print();



    return 0;
}
