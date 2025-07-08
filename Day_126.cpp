#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;
        int i = 0, maxLen = 0;
        for(int j = 0; j < n; j++){
            freq[arr[j]]++;
            while(freq.size() > 2){
                freq[arr[i]]--;
                if(freq[arr[i]] == 0){
                    freq.erase(arr[i]);
                }
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};