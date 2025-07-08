#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int maxsize = -1;
        int i = 0, j = 0;
        unordered_map<char, int> substring;
        while(i < s.size()){
            substring[s[i]]++;
            while(substring.size() > k){
                substring[s[j]]--;
                if(substring[s[j]] == 0)
                    substring.erase(s[j]);
                j++;
            }
            if(substring.size() == k)
                maxsize = max(maxsize, i - j + 1);
            i++;
        }
        return maxsize;
        
    }
};