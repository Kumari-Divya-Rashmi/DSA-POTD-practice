#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
   bool evaluate(int b1, int b2, char op){
        if (op == '&'){
            return b1 & b2;
        }
        else if (op == '|'){
            return b1 | b2;
        }
        else{
            return b1 ^ b2;
        }
    }
    int solve(int start, int end, int req, string &s, vector<vector<vector<int>>> &dp) {
        if (start == end){
           return (req == (s[start] == 'T')) ? 1 : 0;
        }
        if (dp[start][end][req] != -1){
            return dp[start][end][req];
        }
        
        int ans = 0;
        for (int k = start + 1; k < end; k += 2){
            int leftTrue = solve(start, k - 1, 1, s, dp);
            int leftFalse = solve(start, k - 1, 0, s, dp);
            int rightTrue = solve(k + 1, end, 1, s, dp);
            int rightFalse = solve(k + 1, end, 0, s, dp);
            char op = s[k];  

            if(evaluate(1, 1, op) == req){
                ans += leftTrue * rightTrue;
            }
            if(evaluate(1, 0, op) == req){
                ans += leftTrue * rightFalse;
            }
            if(evaluate(0, 1, op) == req){
                ans += leftFalse * rightTrue;
            }
            if(evaluate(0, 0, op) == req){
                ans += leftFalse * rightFalse;
            }
        }
        return dp[start][end][req] = ans;
    }
    int countWays(string &s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n - 1, 1, s, dp);
    }
};