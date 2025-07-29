#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++){
            for (int j = coins[i]; j <= sum; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[sum];
    }
    
};
