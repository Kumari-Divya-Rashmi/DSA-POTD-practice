#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        int maxpos = 0;
        int choice = 0;
        int jumps = 0;
        
        for(int i = 0; i < n - 1; i++){
            maxpos = max(maxpos, arr[i] + i);
            if(i == choice){
                choice = maxpos;
                jumps++;
            }
        }
        if(choice >= n-1) return jumps;
        return -1;
        
        // code here
    }
};