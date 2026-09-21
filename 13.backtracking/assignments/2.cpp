//telephone numbers
#include<iostream>
#include<vector>
using namespace std;
vector <string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void solve(string digits,int idx,string ans){
    if(idx==digits.size()){
        cout<<ans<<"\n";
        return ;
    }
    string letters =mapping[digits[idx]-'0'];
    for(char ch :letters){
        solve(digits,idx+1,ans+ch);
    }
}
int main(){
    string digits = "23";
    string ans="";
    cout<<digits.size()<<"\n";
    solve(digits,0,ans);
    return 0;
}