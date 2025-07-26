#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> freq(26, 0);
        
        for(char c : s){
            freq[c - 'a']++;
        }
        vector<int> nonZeroFreq;
        for(int i = 0; i < 26; ++i){
            if(freq[i] > 0){
                nonZeroFreq.push_back(freq[i]);
            }
        }
        sort(nonZeroFreq.begin(), nonZeroFreq.end());
        
        int n = nonZeroFreq.size();
        if(nonZeroFreq[0] == nonZeroFreq[n - 1]) return true;
        if(nonZeroFreq[0] == 1 && nonZeroFreq[1] == 
        nonZeroFreq[n - 1]) return true;
        if(nonZeroFreq[0] == nonZeroFreq[n - 2] &&
            nonZeroFreq[n - 1] == nonZeroFreq[n - 2] + 1) return true;
        return false;
    }
};