//diameter of a tree
#include <iostream>
#include <vector>
#include <queue>
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int currleft=height(root->left);
    int curright=height(root->right);
    int currheight=max(currleft,curright)+1;

    return currheight;
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }

    int currdiam=height(root->left)+height(root->right)+1;
    int leftdiam=diameter(root->left);
    int rightdiam=diameter(root->right);

    return max(max(leftdiam,rightdiam),currdiam);
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    idx=-1;

    cout<<"diameter: "<<diameter(root)<<endl;
    vector<int> nodes2={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* rot=binaryTrees(nodes2);
    cout<<"diameter: "<<diameter(rot)<<endl;
    
    

    return 0;    
}