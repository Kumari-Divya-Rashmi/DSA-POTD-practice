#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        
        vector<int> dp(sum + 1, INT_MAX);
        
        dp[0] = 0; 
        int n = coins.size();
        
        for (int i = 0; i < n; i++){
            for (int j = coins[i]; j <= sum; j++){
                if (dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if(dp[sum] == INT_MAX){
            return -1;
        }
        return dp[sum];
        // code here
    }
};