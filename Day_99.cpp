#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int findPaths(int node, int dest, vector<vector<int>>& graph, 
    vector<int>& dp){
        if (node == dest) return 1;
        if (dp[node] != -1) return dp[node];
        int totalPaths = 0;
        
        for(int nbr : graph[node]){
            totalPaths += findPaths(nbr,dest,graph,dp);
        }
        return dp[node] = totalPaths;
    }
    int countPaths(vector<vector<int>>& edges,int V,int src,int dest){
        // Code here
        vector<vector<int>> graph(V);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> dp(V, -1);
        return findPaths(src, dest, graph, dp);
    }
};