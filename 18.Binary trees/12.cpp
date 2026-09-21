//subtree of another tree
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

bool isidentical(Node* root1,Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data!=root2->data){
        return false;
    }
    return isidentical(root1->left,root2->left)&& isidentical(root1->right,root2->right);

} 

bool issubtree(Node* root,Node* subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }
    else if(root==NULL || subroot==NULL){
        return false;
    }

    if(root->data==subroot->data){
        if(isidentical(root,subroot)){
            return true;
        }
    }

    int issubleft= issubtree(root->left,subroot);
    if(!issubleft){
        issubtree(root->right,subroot);
    }
    return true;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    Node* subroot=new Node(2);
    subroot->left=new Node(4);
    subroot->right=new Node(5);
    cout<<issubtree(root,subroot);
    return 0;    
}