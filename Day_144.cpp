#include <vector>
#include <unordered_set>
#include <stack>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
       unordered_set<int> invalidDigits(arr.begin(), arr.end());
        vector<int> validDigits;
        for(int i = 0; i <= 9; i++){
            if (!invalidDigits.count(i)){
                validDigits.push_back(i);
            }
        }
        int total;
        if(n == 1){
            total = 9;
        }else{
            total = 9 * pow(10, n - 1);
        } 
        if (validDigits.empty()) 
        return total; 
        int cnt = 0;
        int startDigitCount = 0;
        for(int d : validDigits){
            if (d != 0) startDigitCount++;
        }
        if (startDigitCount == 0) 
        return total; 
        cnt = startDigitCount * pow(validDigits.size(), n - 1);
        return total - cnt;
    }
};
