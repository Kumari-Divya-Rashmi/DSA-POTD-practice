#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + arr[i];
        }
        long long ans = LLONG_MAX;

        for(int i = 0; i < n; i++){
            int low = arr[i];
            int high = low + k;

            long long removeLeft = prefix[i];
            int upper = std::upper_bound(arr.begin(), arr.end(), 
            high) - arr.begin();
            long long removeRight = prefix[n] - prefix[upper] - 
            1LL * (n - upper) * high;
            ans = std::min(ans, removeLeft + removeRight);
        }
        return (int)ans;
    }
};
