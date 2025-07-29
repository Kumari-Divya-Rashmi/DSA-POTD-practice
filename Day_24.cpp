#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
     int maxRob(vector<int>& arr){
         
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        
        int prev = arr[0];
        int secondPrev = 0;
        
        for (int i = 1; i < n; i++){
            int ans = max(prev, secondPrev + arr[i]);
            secondPrev = prev;
            prev = ans;
        }
        return prev;
    }
    int maxValue(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 1) return arr[0];
        
        vector<int> arr1(arr.begin() + 1, arr.end());
        vector<int> arr2(arr.begin(), arr.end() - 1);
        
        int result1 = maxRob(arr1);
        int result2 = maxRob(arr2);
        
        return max(result1, result2); 
        // your code here
        
    }
};
