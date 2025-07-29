#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n;

        auto countLessEqual = [&](int mid) {
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }
            return count;
        };

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};