//lc 394 decode a string
#include<iostream>
#include<string>
#include<stack>
using namespace std;
string decodeStr(string str){
    stack <int> numst;
    stack <string> strst;
    int k=0;
    string ans="";
    for(char c : str){
        if(isdigit(c)){
            k=k*10+(c-'0');
        }
        else if(c=='['){
            numst.push(k);
            strst.push(ans);
            k=0;
            ans="";

        }
        else if(c==']'){
            int repeat=numst.top();numst.pop();
            string prevstr=strst.top();strst.pop();

            for(int i=0;i<repeat;i++){
                prevstr+=ans;
            }
            ans=prevstr;
        }
        else{
            ans+=c;
        }
    }
    return ans;

}
int main(){
    string str="3[a2[c]]";
    cout<<decodeStr(str);
    return 0;
}