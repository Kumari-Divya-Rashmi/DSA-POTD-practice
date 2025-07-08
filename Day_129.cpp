#include <vector>
using namespace std;
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int max_sum = 0;
        for(int i = 0; i < n - 1; ++i){
            int a = arr[i];
            int b = arr[i + 1];
            int pair_sum = a + b;
            max_sum = max(max_sum, pair_sum);
        }
        return max_sum;
    }
};