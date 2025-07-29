#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countWays(string &digits) {
        
        int n = digits.size();
        vector<int> dp(n + 1, -1); 

        dp[n] = 1;

        for (int i = n - 1; i >= 0; --i){
            if (digits[i] == '0'){
                dp[i] = 0;  
            }else{
                dp[i] = dp[i + 1];
                if (i + 1 < n && (digits[i] == '1' || (digits[i] 
                == '2' && digits[i + 1] <= '6'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
        
        // Code here
    }
};
