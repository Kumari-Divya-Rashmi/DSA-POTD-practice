#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < arr.size(); i++) {
            // Remove elements out of this window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove all elements smaller than current from the back
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            // Add current element index
            dq.push_back(i);

            // Add to result if window is ready
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }

        return result;
    }
};    