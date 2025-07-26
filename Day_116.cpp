#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1), prev(n, -1);
        vector<vector<int>> subsets(n);
        
        for(int i = 0; i < n; ++i){
            subsets[i] = {arr[i]};
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0 && dp[j] + 1 >= dp[i]){
                    vector<int> candidate = subsets[j];
                    candidate.push_back(arr[i]);
                    if(dp[j] + 1 > dp[i] || 
                       (dp[j] + 1 == dp[i] && candidate > subsets[i])){
                        dp[i] = dp[j] + 1;
                        subsets[i] = candidate;
                    }
                }
            }
        }
        vector<int> best;
        for(int i = 0; i < n; ++i){
            if(dp[i] > best.size() || 
               (dp[i] == best.size() && subsets[i] > best)){
                best = subsets[i];
            }
        }
        return best;
    }
};


