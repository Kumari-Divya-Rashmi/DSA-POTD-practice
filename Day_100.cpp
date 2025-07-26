#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        vector<int> res;
        int m = pat.length();
        int n = txt.length();
        
        for (int i = 0; i <= n - m; ++i) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                res.push_back(i + 1); // 1-based index
            }
        }
        return res;
    }
};
