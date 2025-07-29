#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        long long int sum = 0;
        long long int powerSumFactor = 1;
        
        for(int i = s.size() - 1; i >= 0; i--){
            sum += (s[i] - '0') * (i + 1) * powerSumFactor;
            powerSumFactor = powerSumFactor * 10 + 1;
        }
        return sum;
    }
};