#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
  bool isPowerOfFive(long long num){
        if (num == 0){
            return false;
        } 
        while (num % 5 == 0){
            num /= 5;
        } 
        return num == 1;
    }
    int cuts(string s) {
        int n = s.length();
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 0; j--){
                if (s[j] == '0'){
                   continue;    
                }
                string sub = s.substr(j, i - j);
                long long num = stoll(sub, nullptr, 2);  
                if(isPowerOfFive(num)){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        if(dp[n] == INF){
            return -1;
        }else{
            return dp[n];
        }
    }
};