//build tree from preorder
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
Node* getIS(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* delNode(Node* root,int value){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data > value){
        root->left= delNode(root->left,value);
    }
    else if(root->data< value){
        root->right= delNode(root->right,value);
       
    }
    else{
        //case 1: no child
        if(root->right ==NULL && root->left==NULL){
            delete root;
            return NULL;
        }
        //case 2:  1 child
        if(root->right ==NULL || root->left==NULL){
            return root->left==NULL ? root->right:root->left;
        }
        //case 3 :2 child (inorder succ replacing)
        Node* IS= getIS(root->right);
        root->data=IS->data;
        root->right=delNode(root->right,IS->data);

    }
    return root;
}
int main(){
    int arr[6] ={5,1,3,4,2,7};
    Node* root=buildBST(arr,6);
   inorder(root);
    delNode(root,7);
   inorder(root);

    return 0;    
}