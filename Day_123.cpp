#include <vector>
#include <unordered_map>
#include <stack>
#include<algorithm>
#include <numeric>
using namespace std;
class Solution {
  public:
    bool isValid(vector<int>& arr, int k, int maxSum) {
        int count = 1, sum = 0;
        for (int num : arr) {
            if (sum + num > maxSum) {
                count++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, k, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
