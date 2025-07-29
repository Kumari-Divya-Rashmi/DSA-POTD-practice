#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int nCr(int n, int r) {
        const int MOD = 1e9 + 7;
        if (r > n) return 0;
        vector<int> C(r + 1, 0);
        C[0] = 1;  

        for (int i = 1; i <= n; ++i) {
            
            for (int j = min(i, r); j > 0; --j) {
                C[j] = (C[j] + C[j - 1]) % MOD;
            }
        }

        return C[r];
    }
};
