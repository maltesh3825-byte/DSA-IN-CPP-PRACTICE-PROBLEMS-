//valid anagram
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool ValidAnagram(string s,string t){
    if(s.size()!=t.size()){
        return false;
    }
    unordered_map <char,int> m;
    for(int i=0;i<s.size();i++){
        if(m[s[i]]){
            m[s[i]]++;
        }
        else{
            m[s[i]]=1;
        }
    }
    for(int i=0;i<t.size();i++){
        if(m[t[i]]){
            m[t[i]]--;
            if(m[t[i]]==0){
                m.erase(t[i]);
            }
        }
        else{
            return false;
        }
    }
    return m.size()==0;

}
int main(){
    string s="rape";
    string t="care";
    cout<<ValidAnagram(s,t);
    return 0;
}