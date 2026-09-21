//top tree view
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
void topview(Node* root){
    queue <pair<Node*,int>> q;
    map <int,int> m;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> curr=q.front();//node,hd
        int currHd=curr.second;
        q.pop();

        if(!m.count(currHd)){
            m[currHd]=curr.first->data;
        }
        if(curr.first->left!=NULL){
            q.push(make_pair(curr.first->left,currHd-1));

        }
        if(curr.first->right!=NULL){
            q.push(make_pair(curr.first->right,currHd+1));
            
        }
    }
    for(auto i:m){
        cout<<i.second<<" ";
    }

}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=binaryTrees(nodes);
    topview(root);
    return 0;    
}