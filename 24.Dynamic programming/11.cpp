//longest common subsquence by memoization
#include<iostream>
#include<vector>
using namespace std;
int lcsRec(string str1, string str2, vector<vector<int>> &  dp){

    if(str1.size()==0 || str2.size()==0)return 0;

    
    int n= str1.size();
    int m= str2.size();

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[n-1]==str2[m-1]){
        dp[n][m]= 1+ lcsRec(str1.substr(0,n-1), str2.substr(0,m-1),dp);
    }
    
    else{
        int a1=lcsRec(str1, str2.substr(0,m-1),dp);
        int a2=lcsRec( str1.substr(0,n-1), str2,dp);
        dp[n][m]= max(a1,a2);
    }

    return dp[n][m];
}
int main(){
    string str1= "abcdge";
    string str2= "abedg";

    
    int n= str1.size();
    int m= str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<lcsRec(str1,str2, dp);
    return 0;
}