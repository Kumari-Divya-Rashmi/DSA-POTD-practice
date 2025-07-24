#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:

    int longestStringChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int maxLength = 1;  
        for (const string& word : words) {
            dp[word] = 1;  
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);  // Remove character at index i
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            maxLength = max(maxLength, dp[word]);
        }
        return maxLength;
    }
};