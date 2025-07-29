#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        unordered_map<char, int> freq;
        for (char ch : s){
            freq[ch]++;
        }
        int totalSubstrings = 0;
        for (auto& item : freq){
            int countOfChar = item.second;
            totalSubstrings += countOfChar*(countOfChar - 1)/2
            +countOfChar;
        }
        return totalSubstrings;
    }
};