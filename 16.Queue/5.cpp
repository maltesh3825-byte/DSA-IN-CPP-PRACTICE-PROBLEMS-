//non repeat letter
#include<iostream>
#include<queue>
using namespace std;
void nonRepeat(string s){
    queue <char> q;
    int freq[26]={0};
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty()&&freq[q.front()-'a']>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1";
            
        }
        cout<<q.front();
    }
}
int main(){
    string str="aabccxb";
    nonRepeat(str);
    return 0;
}