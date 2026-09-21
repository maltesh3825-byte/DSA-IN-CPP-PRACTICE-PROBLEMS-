//lowest common ancestor
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
bool rootToNodePath(Node* root,int n,vector <int>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    int isleft=rootToNodePath(root->left,n,path);
    int isright=rootToNodePath(root->right,n,path);

    if(isleft||isright){
        return true;
    }

    path.pop_back();
    return false;

}

int LCA(Node* root,int n,int m){
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root,n,path1);
    rootToNodePath(root,m,path2);

    int lca=-1;
    for(int i=0,j=0;i<path1.size()&&j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;

}
Node* lca2(Node* root,int n,int m){
    if(root==NULL){
        return NULL;
    }
    
    Node* llca=lca2(root->left,n,m);
    Node* rlca=lca2(root->right,n,m);

    if(root->data==n|| root->data==m){
        return root;
    }
    if (llca!=NULL && rlca != NULL){
        return root;
    }
    

    return llca==NULL ? rlca : llca;
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    //cout<<"lca: "<<LCA(root,4,3); // tc -> O(n)  ;  sc ->O(n)
    cout<<"lca: "<<lca2(root,4,3)->data; //optimized sp O(n) to O(1); tc -> O(n)
    return 0;    
}