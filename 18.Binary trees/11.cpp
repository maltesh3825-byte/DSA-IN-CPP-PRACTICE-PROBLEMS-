//diameter of a tree 2nd approach optimized O(n)
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

pair<int,int> diameter(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftinfo =diameter(root->left);
    pair<int,int> rightinfo =diameter(root->right);
    //daim,ht
    int currdiam=leftinfo.second+rightinfo.second+1;
    int finaldiam=max(currdiam,max(leftinfo.first,rightinfo.first));
    int finalht=max(rightinfo.second,leftinfo.second)+1;

    return make_pair(finaldiam,finalht);
}   
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    idx=-1;

    cout<<"diameter: "<<diameter(root).first<<endl;
    vector<int> nodes2={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* rot=binaryTrees(nodes2);
    cout<<"diameter: "<<diameter(rot).first<<endl;
    
    

    return 0;    
}