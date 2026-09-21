//longest common subsquence by recursion
#include<iostream>
using namespace std;
int lcsRec(string str1, string str2){

    if(str1.size()==0 || str2.size()==0)return 0;

    int n= str1.size();
    int m= str2.size();

    if(str1[n-1]==str2[m-1]){
        return  1+ lcsRec(str1.substr(0,n-1), str2.substr(0,m-1));
    }
    else{
        int a1=lcsRec(str1, str2.substr(0,m-1));
        int a2=lcsRec( str1.substr(0,n-1), str2);
        return max(a1,a2);
    }
}
int main(){
    string s1= "abcdge";
    string s2= "abedg";
    cout<<lcsRec(s1,s2);
    return 0;
}