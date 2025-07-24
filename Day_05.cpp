#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        unordered_map<int, int> prefixIndex;
        int curr_sum = 0, maxLen = 0;
        int start = -1, end = -1;

        for (int i = 0; i < arr.size(); i++) {
            curr_sum += arr[i];

            if (curr_sum == x) {
                maxLen = i + 1;
                start = 0;
                end = i;
            }

            if (prefixIndex.find(curr_sum - x) != prefixIndex.end()) {
                if (i - prefixIndex[curr_sum - x] > maxLen) {
                    maxLen = i - prefixIndex[curr_sum - x];
                    start = prefixIndex[curr_sum - x] + 1;
                    end = i;
                }
            }

            // Store first occurrence only
            if (prefixIndex.find(curr_sum) == prefixIndex.end()) {
                prefixIndex[curr_sum] = i;
            }
        }

        vector<int> result;
        if (maxLen == 0) return result; // No such subarray

        for (int i = start; i <= end; i++) {
            result.push_back(arr[i]);
        }

        return result;
    }
};
