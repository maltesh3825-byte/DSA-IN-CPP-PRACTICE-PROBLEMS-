//building a trie
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

    bool startsWith(string prefix) {
    Node* temp = root;
    for (int i = 0; i < prefix.size(); i++) {
        // If the character is not in the children map, the prefix doesn't exist
        if (temp->children.count(prefix[i]) == 0) {
            return false;
        }
        // Move to the next node
        temp = temp->children[prefix[i]];
    }
    // If we successfully traversed the entire prefix, it exists
    return true;
}
};


int main(){
    vector<string> words={"the","a","there","their","any","thee"};
    Trie  trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    cout<<trie.search("ther");
    return 0;
}