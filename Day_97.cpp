#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int atMostKDistinct(string& s, int k) {
        int count = 0;
        int left = 0;
        vector<int> freq(26, 0); // Only lowercase letters
        int distinct = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (freq[s[right] - 'a'] == 0) {
                distinct++;
            }
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int countSubstr(string& s, int k) {
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }
};
