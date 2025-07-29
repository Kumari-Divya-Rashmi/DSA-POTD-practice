#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        const int mod = 1e9 + 7;
        vector<int> row;
        row.push_back(1);  

        long long prev = 1;
        for (int k = 1; k < n; ++k) {
            long long curr = (prev * (n - k)) % mod;
            curr = (curr * powMod(k, mod - 2, mod)) % mod;  
            row.push_back(curr);
            prev = curr;
        }

        return row;
    }

  private:
    long long powMod(long long a, long long b, long long mod) {
        long long result = 1;
        a = a % mod;
        while (b > 0) {
            if (b & 1) result = (result * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }
};

