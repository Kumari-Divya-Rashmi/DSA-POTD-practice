#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_set<char> uniquechars(str.begin(), str.end());
        int target = uniquechars.size();
        unordered_map<char, int> counts;
        int left = 0, right = 0, formed = 0;
        int minlen = INT_MAX;
        while(right < str.size()){    
            char c = str[right];
            counts[c]++;
            if(counts[c] == 1)
                formed++;
            while(formed == target){
                minlen = min(minlen, right - left + 1);
                char leftchar = str[left];
                counts[leftchar]--;
                if(counts[leftchar] == 0)
                    formed--;
                left++;
            }
            right++;
        }
        return minlen;
    }
};