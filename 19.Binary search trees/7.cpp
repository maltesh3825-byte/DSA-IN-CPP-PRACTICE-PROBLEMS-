//sorted to balanced bst
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
Node* balancedBst(int arr[],int s,int e){
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
int main(){
    int arr[]={3,4,5,6,7,8,9};
    Node* root=balancedBst(arr,0,6);
    preorder(root);
    return 0;    
}