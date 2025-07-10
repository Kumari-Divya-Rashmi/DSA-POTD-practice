#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long res = 0;
        long long currSum = 0;
        stack<int> values;
        stack<int> counts;
        
        for(int i = 0; i < n; ++i){
            int count = 1;
            while(!values.empty() && values.top() >= arr[i]){
                currSum -= (long long)values.top() * counts.top();
                count += counts.top();
                values.pop();
                counts.pop();
            }
            values.push(arr[i]);
            counts.push(count);
            currSum += (long long)arr[i] * count;
            res = (res + currSum) % MOD;
        }
        return (int)res;
    }
};