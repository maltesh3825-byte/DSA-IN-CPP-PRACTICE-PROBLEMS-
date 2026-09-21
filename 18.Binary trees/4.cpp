//tree traversal
//post order traversal
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
void postorder(Node* root){
    if(root==NULL){
        return ;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    postorder(root);   
    return 0;    
}