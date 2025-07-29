#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> firstIndex;
        int maxLen = 0, prefixSum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prefixSum += (arr[i] > k) ? 1 : -1;
            if (prefixSum > 0) {
                maxLen = i + 1;
            }
            if (firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefixSum - 1]);
            }

            if (firstIndex.find(prefixSum) == firstIndex.end()) {
                firstIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};