//find subsets
#include<iostream>
#include<string>
using namespace std;
void sub(string str,string subset){
    
    if(str.size()==0){
        cout<<subset<<"\n";
        return ;
    }
    char ch=str[0];
    sub(str.substr(1,str.size()-1),subset+ch);//yes
    sub(str.substr(1,str.size()-1),subset);//no

}
int main(){
    string str="abc";
    string subset="";
    sub(str,subset);
    return 0;
}