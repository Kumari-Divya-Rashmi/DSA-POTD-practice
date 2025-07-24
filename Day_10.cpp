#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
  public:
  
  int length(int left, int right,string &s){
      int cnt = 0;
        while(left >= 0 && right < s.size()){
            if(s[left] == s[right]){
                cnt += 2;
                left--;
                right++;
            }
            else break;
        }
        return cnt;
      
  }
    string longestPalindrome(string &s) {
        
        int n = s . size();
        int maxlen = 1;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            int cnt = 1 + length(i - 1, i + 1, s);
            if(cnt > maxlen){
              maxlen = cnt;
              start = i-cnt / 2;
            }
        }
        for(int i = 1; i < n; i++){
            int cnt = length(i - 1, i, s);
            if(cnt > maxlen){
            maxlen = cnt;
            start = i-cnt / 2;
            }
        }
        return s.substr(start, maxlen);
        
        // code here
        
    }
};
