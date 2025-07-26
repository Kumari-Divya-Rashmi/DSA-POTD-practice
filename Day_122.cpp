#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());  // Step 1: sort b
        vector<int> res;

        for (int x : a) {
            // upper_bound returns iterator to first element > x
            int count = upper_bound(b.begin(), b.end(), x) - b.begin();
            res.push_back(count);
        }

        return res;
    }
};
