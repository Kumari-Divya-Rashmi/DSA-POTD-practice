#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq;
        int i = 0;
        int cnt = 0;
        for(int j = 0; j < arr.size(); j++){
            freq[arr[j]]++;
            while(freq.size() > k ){
                freq[arr[i]]--;
                if(freq[arr[i]] == 0){
                    freq.erase(arr[i]);
                    
                }
                i++;
            }
            cnt += (j - i + 1);
        }
        return cnt;
    }
};