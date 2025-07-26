#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int computeSum(const vector<int>& arr, int divisor){
        int total = 0;
        for(int num : arr){
            total += (num + divisor - 1) / divisor; 
        }
        return total;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int left = 1, right = *max_element(arr.begin(), arr.end());
        int result = right;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(computeSum(arr, mid) <= k){
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return result;
    }
};           