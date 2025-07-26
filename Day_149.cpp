#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        int totalSum = arr[0];
        int currMax = arr[0];
        int currMin = arr[0];
        int maxLinearSum = arr[0];
        int minLinearSum = arr[0];
        for(int i = 1; i < n; i++){  
            int num = arr[i];
            totalSum += num;
            currMax = max(num, currMax + num);
            maxLinearSum = max(maxLinearSum, currMax);
            currMin = min(num, currMin + num);
            minLinearSum = min(minLinearSum, currMin);
        }
        if(maxLinearSum < 0){
            return maxLinearSum;
        }
        return max(maxLinearSum, totalSum - minLinearSum);
    }
};
