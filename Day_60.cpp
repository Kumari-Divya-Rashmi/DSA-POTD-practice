#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string multiplyStrings(string &s1, string &s2) {
        // Handle negative signs
        bool isNegative = false;
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1);
        }

        int n = s1.size();
        int m = s2.size();
        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string res;
        for (int num : result) {
            if (!(res.empty() && num == 0))
                res += to_string(num);
        }

        if (res.empty())
            return "0";

        if (isNegative)
            res = "-" + res;

        return res;
    }
};
