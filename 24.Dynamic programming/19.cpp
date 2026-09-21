//minimum partitioning
#include<iostream>
#include<vector>
using namespace std;
int getdiff(vector<int> nums){
    int totsum =0;
    for(auto i :nums){
        totsum+=i;
    }
    int w = totsum/2;
    int n=nums.size();
    vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
    for(int i=1;i<n+1 ; i++){
        for(int j=1;j<w+1;j++){
            if(nums[i-1]<=j){
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int grp1sum = dp[n][w];
    int grp2sum= totsum - grp1sum;
    return abs(grp1sum - grp2sum);
}
int main(){
    vector<int> n = {1,6,11,5};
    cout<<getdiff(n)<<endl;
    return 0;
}