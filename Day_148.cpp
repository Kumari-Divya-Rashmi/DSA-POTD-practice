#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right){
        // code here
        int Time = 0;
        for(int pos : left){
            Time = max(Time, pos);
        }
        for(int pos : right){
            Time = max(Time, n - pos);
        }
        return Time;
    }
};