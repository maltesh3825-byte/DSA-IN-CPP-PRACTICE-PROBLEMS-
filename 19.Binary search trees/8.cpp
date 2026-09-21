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

static int idx=-1;

Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
         root->right=insert(root->right,val);
    }
    return root;
}
Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void getinorder(Node* root,vector<int> & arr){
    if(root==NULL){
        return;
    }
    getinorder(root->left,arr);
    arr.push_back(root->data);
    getinorder(root->right,arr);

}
Node* buildbst(Node* root){
    vector<int> arr;
    getinorder(root,arr);
    
    Node* curr=balancedBst(arr,0,arr.size()-1);
    return curr;
}
int main(){
    
    Node* root=new Node(6);
    root->left=new Node(5);   
    root->left->left=new Node(4);   
    root->left->left->left=new Node(3);
    
    root->right=new Node(7);   
    root->right->right=new Node(8);   
    root->right->right->right=new Node(9);
    preorder(root);
    Node* c=buildbst(root);
    cout<<endl;
    preorder(c);

    
    return 0;    
}