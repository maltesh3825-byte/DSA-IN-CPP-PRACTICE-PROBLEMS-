//prefix problem
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Node{
public:
    unordered_map<char,Node*> children;
    bool endofword;
    int freq;
    Node(){
        endofword=false;
        freq=0;
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
                temp->children[key[i]]->freq=1;
            }
            else{
                temp->children[key[i]]->freq++;
            }
            temp=temp->children[key[i]];
        }
        temp->endofword=true;
    }

    string getprefix(string key){
        Node* temp=root;
        string prefix="";
        for(int i=0;i<key.size();i++){
            prefix+=key[i];
            if(temp->children[key[i]]->freq==1){
                break;
            }
            temp=temp->children[key[i]];
        }
        return prefix;
    }

   

};
 void prefixprob(vector<string>  dic){
        Trie trie;
        for(int i=0;i<dic.size();i++){
            trie.insert(dic[i]);
        }
        for(int i=0;i<dic.size();i++){
            cout<<trie.getprefix(dic[i])<<endl;
        }
    }



int main(){
    vector<string> words={"zebra","dog","dove","duck"};
    prefixprob(words);
    return 0;
}