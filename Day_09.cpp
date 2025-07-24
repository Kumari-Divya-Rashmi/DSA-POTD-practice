#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int longestPalinSubseq(string &s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};
