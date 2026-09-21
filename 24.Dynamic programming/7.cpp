// 0 - 1 knapsack using tabulation
#include<iostream>
#include<vector>
using namespace std;
int knapsackTab(vector<int> val, vector<int> wt, int W, int n){
    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            int itmWt = wt[i-1];
            int itmVal = val[i-1];

            if(itmWt <=j){
                dp[i][j] = max(itmVal + dp[i-1][j-itmWt], dp[i-1][j]);
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;
        
    }
    
    return dp[n][W];
}
int main(){

    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int n=5;
    int W =7;
    cout<<knapsackTab(val, wt, W, n);
    return 0;


}