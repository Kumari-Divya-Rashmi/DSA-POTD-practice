#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        vector<pair<int, int>> diff;

        for (int num : arr) {
            if (num == x) continue; // exclude x
            int d = abs(num - x);
            diff.push_back({d, -num});  // -num to prioritize higher values
        }

        // Sort by: distance ascending, value descending
        sort(diff.begin(), diff.end());

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(-diff[i].second);  // negate to restore original number
        }

        return ans;
    }
};
