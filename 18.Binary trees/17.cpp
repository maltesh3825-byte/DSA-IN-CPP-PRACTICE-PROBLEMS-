//kth ancestor of a node in binary tree
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

Node* binaryTrees(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node* currnode=new Node(nodes[idx]);
    currnode->left=binaryTrees(nodes);
    currnode->right=binaryTrees(nodes);

    return currnode;
}
int kthancestor(Node* root,int node,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        return 0;
    }
    int leftdis=kthancestor(root->left,node,k);
    int rightdis=kthancestor(root->right,node,k);
    if(leftdis==-1 &&  rightdis==-1){
        return -1;
    }

    int validval =leftdis==-1 ? rightdis:leftdis;
    if(validval+1==k){
        cout<<"kth ances : "<<root->data<<endl;
    }

    return validval+1;
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    kthancestor(root,4,2);
    return 0;    
}