#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int lis(vector<int>& arr) {
        vector<int> temp;

        for (int num : arr) {
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if (it == temp.end()) {
                temp.push_back(num);
            } else {
                *it = num; // Replace with smaller value
            }
        }

        return temp.size();
    }
};
