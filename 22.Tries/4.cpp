//count unique substring
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Node{
public:
    unordered_map<char,Node*> children;
    bool endofword;

    Node(){
        endofword=false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endofword=true;
    }

    bool search(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return temp->endofword;
    }
    int prefixhelper(Node*root){
        int ans=0;
        for(pair<char,Node*>child:root->children){
            ans+=prefixhelper(child.second);
        }
        return ans+1;
    }
    int countprefix(){
        return prefixhelper(root);
    }

   
};
int countuniqsub(string str){
    Trie trie;
   
    for(int i=0;i<str.size();i++){
         string suf=str.substr(i);
         trie.insert(suf);
    }

    return trie.countprefix();
}


int main(){
    cout<<countuniqsub("ababa");
    return 0;
}