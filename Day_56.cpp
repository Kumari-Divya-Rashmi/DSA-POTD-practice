#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;
        for (int num : arr) {
            xor_all ^= num;
        }
        int diff_bit = xor_all & -xor_all;

        int a = 0, b = 0;
        for (int num : arr) {
            if (num & diff_bit)
                a ^= num;
            else
                b ^= num;
        }

        if (a > b)
            swap(a, b);

        return {a, b};
    }
};
