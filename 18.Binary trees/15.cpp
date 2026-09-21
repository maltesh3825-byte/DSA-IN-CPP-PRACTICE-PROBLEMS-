//cout all elements at kth level
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
void kthhelper(Node* root,int currlvl,int k){
    if(root==NULL){
        return ;
    }
    if(currlvl==k){
        cout<<root->data<<" ";
    }

    kthhelper(root->left,currlvl+1,k);
    kthhelper(root->right,currlvl+1,k);
}
void kth(Node* root,int k){
    kthhelper(root,1,k);
    return ;
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    kth(root,3);

    return 0;    
}