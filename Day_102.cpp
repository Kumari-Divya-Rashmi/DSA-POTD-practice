#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidNumber(const string &num){
        return !(num.size() > 1 && num[0] == '0');
    }
    string addStrings(const string &num1, const string &num2){
        string result;
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 || j >= 0 || carry){
            int digit1 = i >= 0 ? num1[i--] - '0' : 0;
            int digit2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool checkSumString(const string &s, int start, string first, string second) {
        if (!isValidNumber(first) || !isValidNumber(second)) return false;
        string sum = addStrings(first, second);
        int sumLen = sum.length();
        if (start + sumLen > s.length() || s.substr(start, sumLen) != sum)
            return false;
        if (start + sumLen == s.length()) return true;
        return checkSumString(s, start + sumLen, second, sum);
    }
    bool isSumString(string &s) {
        int n = s.size();
        for(int i = 1; i <= n / 2; ++i){
            for(int j = 1; j <= (n - i) / 2; ++j){
                string first = s.substr(0, i);
                string second = s.substr(i, j);
                if (checkSumString(s, i + j, first, second))
                    return true;
            }
        }
        return false;
    }
};