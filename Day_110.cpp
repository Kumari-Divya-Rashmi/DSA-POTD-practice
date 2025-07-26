#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool cheak(vector<int>& heights, vector<int>& cost, int mid){
        
        long long costmid = 0;
        long long costmidright = 0;
      
        for(int i = 0; i < heights.size(); i++){
          costmid  += (long long)abs(heights[i] - mid) * cost[i];
          costmidright += (long long)abs(heights[i] - (mid + 1)) * cost[i];
       }  
       return costmid < costmidright;
   }
    int minCost(vector<int>& heights, vector<int>& cost) {
        
        int sum  = 0;
        int low =*min_element(heights.begin(),heights.end());
        int high = *max_element(heights.begin(),heights.end());
        
        while(low <= high){
            int mid = (high + low) / 2;
            if(cheak(heights, cost, mid)){
                
                sum = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        long long result = 0;
        for(int i = 0; i < heights.size(); i++){
            result += (long long)abs(heights[i] - sum) * cost[i];
        }
        return (int)result; 
    }
};
