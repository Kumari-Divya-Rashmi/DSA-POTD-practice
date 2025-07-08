#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    int substrCount(string &s, int k) {
        int n = s.length();
        if(k > n) return 0;
        unordered_map<char, int> freq;
        int count = 0;
        for(int i = 0; i < k; ++i){
            freq[s[i]]++;
        }
        if(freq.size() == k - 1) count++;
        for(int i = k; i < n; ++i){
            char out_char = s[i - k];  
            char in_char = s[i];       
          
            freq[out_char]--;
            if(freq[out_char] == 0){
                freq.erase(out_char);
            }
            freq[in_char]++;
            if(freq.size() == k - 1){
                count++;
            }
        }
        return count;
    }
};

