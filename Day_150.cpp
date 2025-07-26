#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        // int m = floor(n/3);
        vector<int> ans;
        unordered_map<int,int>freq;
        for(int num : arr){
            freq[num]++;
        }
        for(auto it : freq){
            if(it.second > floor(n/3)){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};