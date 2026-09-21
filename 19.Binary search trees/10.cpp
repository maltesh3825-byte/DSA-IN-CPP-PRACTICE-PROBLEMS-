//given bst to balanced bst
#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int dat){
        this->data=dat;
        left=right=NULL;
    }
};


void getinorder(Node* root,vector<int> & arr){
    if(root==NULL){
        return;
    }
    getinorder(root->left,arr);
    arr.push_back(root->data);
    getinorder(root->right,arr);

}
Node* balancedBst(vector<int> &arr,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = s+ (e-s)/2;
    Node* root=new Node(arr[mid]);
    root->left= balancedBst(arr,s,mid-1);
    root->right= balancedBst(arr,mid + 1,e);
    return root;
}
Node* mergeBst(Node* r1,Node* r2){
    vector<int> v1;
    vector<int> v2;
    vector<int> m;

    getinorder(r1,v1);
    getinorder(r2,v2);

    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            m.push_back(v1[i++]);
        }
        else{
            m.push_back(v2[j++]);
        }

    }
    while(i<v1.size()){
        m.push_back(v1[i++]);
    }
    while(j<v2.size()){
        m.push_back(v2[j++]);
    }
 
    return balancedBst(m,0,m.size()-1);

}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    
    Node* root1=new Node(2);
    root1->left=new Node(1);   
    root1->right=new Node(4);   
    
    Node* root2=new Node(9);
    
    root2->left=new Node(3);   
    root2->right=new Node(12);   
    
    Node* c=mergeBst(root1,root2);
    preorder(c);
    
   


    
    return 0;    
}