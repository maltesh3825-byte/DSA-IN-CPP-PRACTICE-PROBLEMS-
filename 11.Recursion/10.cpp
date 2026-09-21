//removing duplicates using recursion
#include<iostream>
using namespace std;
void remdup(string str,int i,string ans,int map[]){
    int n=str.size();
    if(i==n){
        cout<<ans;
        return ;
    }
    int mapidx=((int)str[i]-'a');
    
    if(map[mapidx]==true){
        remdup(str,i+1,ans,map);
    }
    else{
        map[mapidx]=true;
        remdup(str,i+1,ans+str[i],map);
    }

}
int main(){
    string str="appnnacollege";
    int map[26]={false};
    string ans="";
    remdup(str,0,ans,map);
    return 0;
}
