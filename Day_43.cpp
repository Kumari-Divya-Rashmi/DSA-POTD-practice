#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
       int n = houses.size();
        vector<bool> inMST(n, false); 
        vector<int> minDist(n, INT_MAX); 
        minDist[0] = 0; 
        int cost = 0;
        for(int i = 0; i < n; ++i){
            int u = -1;
            for(int j = 0; j < n; ++j){
                if(!inMST[j] && (u == -1 || minDist[j] < minDist[u])){
                    u = j;
                }
            }
            inMST[u] = true;
            cost += minDist[u];
            for(int v = 0; v < n; ++v){
                if(!inMST[v]){
                    int dist = abs(houses[u][0] - houses[v][0]) + 
                    abs(houses[u][1] - houses[v][1]);
                    if(dist < minDist[v]){
                        minDist[v] = dist;
                    }
                }
            }
        }
        return cost;
        
    }
};

