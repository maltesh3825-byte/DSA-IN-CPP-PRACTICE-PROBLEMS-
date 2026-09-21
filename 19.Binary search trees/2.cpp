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
bool search(Node* root,int value){
    if(root == NULL){
        return false;
    }
    if(root->data == value){
        return true ;
    }
    if(root->data < value){
        return search(root->right,value);
    }
    else{
       return search(root->left,value);
    }
}
int main(){
    int arr[6] ={5,1,3,4,2,7};
    Node* root=buildBST(arr,6);
   
    cout<<search(root,7);
    return 0;    
}