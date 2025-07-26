#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        int maxlen = 1;
        int LisSum = INT_MAX;
        vector<int> len(n, 1); 
        vector<int> sum(n);
        for (int i = 0; i < n; i++){
            total += arr[i];
        }
        for(int i = 0; i < n; i++){
            sum[i] = arr[i];
            for(int j = 0; j < i; j++){
                if (arr[j] < arr[i]){
                    if(len[j] + 1 > len[i]){
                        len[i] = len[j] + 1;
                        sum[i] = sum[j] + arr[i];
                    }else if(len[j] + 1 == len[i]){
                        sum[i] = min(sum[i], sum[j] + arr[i]);
                    }
                }
            }
            maxlen = max(maxlen, len[i]);
        }
        for(int i = 0; i < n; i++){
            if(len[i] == maxlen){
                LisSum = min(LisSum, sum[i]);
            }
        }
        return total - LisSum;
    }
};
