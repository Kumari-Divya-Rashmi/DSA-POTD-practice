#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        
       int n = arr.size();
       if(n == 1) return arr[0];
       if(n == 2) return max(arr[0],arr[1]);
       
       int prev = arr[0];
       int secondprev = 0;
       int ans = 0;
       
       for(int i = 1; i < n; i++){
           ans = max(prev,secondprev + arr[i]);
           secondprev = prev;
           prev = ans;
       }
       return ans;
      // code here
    }
};