#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countStrings(string &s) {
        // code here
        vector<int> map(26, 0);
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            ans += i - map[s[i] - 'a'];
            map[s[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(map[s[i] - 'a'] > 1){
                ans++;
                break;
            }
        }
        return ans;
    }
};