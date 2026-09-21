//longest word with all prefix
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

    void longesthelper(Node* root,string &ans,string temp){
        for(pair<char,Node*> child:root->children){
            if(child.second->endofword){
                temp+=child.first;
                if((temp.size()==ans.size() && temp<ans ) || temp.size()>ans.size()){
                    ans=temp;
                }
            }
            longesthelper(child.second,ans,temp);
            temp=temp.substr(0,temp.size()-1);
        }
        
    }
    string longeststrwithEOW(){
        string ans="";
        longesthelper(root,ans,"");
        return ans;
    }

};

string longeststring(vector<string> dic){
    Trie trie;
    for(int i=0;i<dic.size();i++){
        trie.insert(dic[i]);
    }
    return trie.longeststrwithEOW();

}
int main(){
    vector<string> dic={"a","banana","app","appl","ap","apply","apple"};
    cout<<longeststring(dic);
    return 0;
}