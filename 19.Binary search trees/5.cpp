//path to leaf
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
void printpath(vector<int> p){
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
void helper(Node * root,vector<int> & path){
    if(root==NULL){
        return ;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        printpath(path);
        path.pop_back();
        return;
    }
    helper(root->left,path);
    helper(root->right,path);
        path.pop_back();
    
}
void pathtoleaf(Node* root){
    vector<int> path;
    helper(root,path);
}
int main(){
    int arr[9] ={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    pathtoleaf(root);   
    return 0;    
}