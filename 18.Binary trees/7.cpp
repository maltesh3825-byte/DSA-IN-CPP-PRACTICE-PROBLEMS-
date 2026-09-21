//max height of a binary tree

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
void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    
    if(q.front()==NULL){
        return ;
    }
    q.push(NULL);

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }
        else{
            cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
         if(curr->right!=NULL){
            q.push(curr->right);
        }
        }
    }
    
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

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    idx=-1;

    cout<<"height: "<<height(root);
    vector<int> nodes2={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* rot=binaryTrees(nodes2);
    cout<<"height: "<<height(rot);
    

    return 0;    
}