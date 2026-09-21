// rod cutting
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(vector<int> prices, vector<int> length, int rodLength) {
    int n = length.size();
    vector<vector<int>> dp(n + 1, vector<int>(rodLength + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= rodLength; j++) {
            dp[i][j] = dp[i - 1][j];

            if (length[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - length[i - 1]] + prices[i - 1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][rodLength];
}
int main(){
    vector<int> p={1,5,8,9,10,17,17,20};
    vector<int> l={1,2,3,4,5,6,7,8};
    cout<<rodCutting(p,l,8);
    return 0;
}