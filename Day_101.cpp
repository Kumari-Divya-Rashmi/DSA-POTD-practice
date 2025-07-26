#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> prefixMap;
        int maxLen = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += a1[i] - a2[i];

            if (sum == 0) {
                maxLen = i + 1;
            }

            if (prefixMap.find(sum) != prefixMap.end()) {
                maxLen = max(maxLen, i - prefixMap[sum]);
            } else {
                prefixMap[sum] = i;
            }
        }

        return maxLen;
    }
};
