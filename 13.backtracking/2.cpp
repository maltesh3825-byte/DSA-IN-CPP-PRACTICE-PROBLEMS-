 //find permutations
#include<iostream>
using namespace std;
void perm(string str,string ans){
    int n= str.size();
    if(n==0){
        cout<<ans<<"\n";
        return ;
    }
    for(int i=0;i<str.size();i++){
        char ch =str[i];
        string nxtstr=str.substr(0,i)+str.substr(i+1,str.size()-i-1);
        perm(nxtstr ,ans+ch);
    }
}
int main(){
    string str="abc";
    string ans="";
    perm(str,ans);
    return 0;
}