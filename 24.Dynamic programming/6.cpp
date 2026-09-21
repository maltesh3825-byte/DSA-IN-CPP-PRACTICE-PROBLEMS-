//0 -1 knapsack using memoization
#include<iostream>
#include<vector>
using namespace std;
int knapSackMem(vector<int> val, vector<int> wt, int W, int n,vector<vector<int>> & dp){
    if(n==0 || W==0){
        return 0;
    }

    if(dp[n][W]!=-1){
        return dp[n][W];
    }

    int itmWt= wt[n-1];
    int itmVal = val[n-1];

    if(itmWt<=W){
        //include
        int ans1= knapSackMem(val,wt,W-itmWt, n-1,dp) + itmVal;
        
        //exclude
        int ans2= knapSackMem(val,wt,W, n-1,dp) ;
        
        return dp[n][W] = max(ans1, ans2);
    }
    else{
        //exclude   
        return dp[n][W] = knapSackMem(val, wt, W, n-1,dp);
    }
}

int main(){
    vector<int> val ={15,14,10,45,30};
    vector<int> wt ={2,5,1,3,4};
    int n= 5;
    int W= 7;

    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    cout<<knapSackMem(val, wt, W, n,dp)<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
