//contiguous substring
#include<iostream>
using namespace std;
int Sub(string st,string ans,int i,int j,int n,bool isprsnt,int count){
    if(i==n){
        return Sub(st,ans,0,j+1,n,isprsnt,count);
        i=j;
    }
    if(st[i]==ans[ans.size()-1]){
        count++;
        isprsnt=true;
        return Sub(st,ans,i+1,j,n,isprsnt,count);
    }
    
    
    if(j==n){
        return count;
    }
    if(j==n && !isprsnt){
        cout<<"no contiguous substring found\n";
        return count;
    }

}
int main(){
    string st="abcab";
    string ans="";
    cout<<Sub(st,ans,0,0,st.size(),false,0);
    return 0;
}