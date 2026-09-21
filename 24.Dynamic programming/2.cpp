//climbing stairs memoization
#include<iostream>
#include<vector>
using namespace std;
int climMemo(int n, vector<int> & dp){
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=climMemo(n-1,dp)+climMemo(n-2,dp);
}
int main(){
    int n=6;
    vector<int> dp(n+1,-1);
    cout<<climMemo(n,dp);
    return 0;
}