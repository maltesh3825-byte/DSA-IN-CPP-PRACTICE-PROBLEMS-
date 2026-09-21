//size of the largest bst in a given binary tree
#include <iostream>
#include <vector>
#include <climits>
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
class Info{
public:     
    bool isBst;
    int min;
    int max;
    int sz;

    Info(bool isBst,int min,int max,int sz){
        this->isBst=isBst;
        this->min=min;
        this->max=max;
        this->sz=sz;
    }
};
static int maxsize;

Info* largestBst(Node* root){
    if(root==NULL){
        return new Info(true,INT_MAX,INT_MIN,0);

    }
    Info* lI=largestBst(root->left);
    Info* rI=largestBst(root->right);

    int currmin=min(root->data,min(lI->min,rI->min));
    int currmax=max(root->data,max(lI->max,rI->max));
    int currsize=lI->sz+rI->sz+1;

    //check for isBst

    if(lI->isBst && rI->isBst && root->data >lI->max && root->data <rI->min){
        maxsize=max(maxsize,currsize);
        return new Info(true,currmin,currmax,currsize);
    }
    
    return new Info(false,currmin,currmax,currsize);

}       

int main(){
    
    Node* root=new Node(50);
    root->left=new Node(30);   
    root->left->left=new Node(5);   
    root->left->left->right=new Node(20);
    
    root->right=new Node(60);   
    root->right->left=new Node(45);   
   
    root->right->right=new Node(70);   
    root->right->right->left=new Node(65);   
    root->right->right->right=new Node(80);
    largestBst(root);
    cout<<"maxsize : "<<maxsize;
   
    return 0;    
}