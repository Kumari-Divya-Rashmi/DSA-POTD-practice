#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, 
        vector<int> &low, vector<vector<int>> &result, 
        unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
        
        vis[node] = true;
        disc[node] = low[node] = timer++;
        
        for(auto it: adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it, node, timer, disc, low, result, adj, vis);
                low[node] = min(low[node], low[it]);
                if(low[it] > disc[node]){
                    result.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[node], disc[it]);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        vector<int> disc(V, -1);  
        vector<int> low(V, -1);  
        unordered_map<int, bool> vis;
        
        vector<vector<int>> result; 
        for(int i = 0; i < V; i++){
            if(!vis[i]) {
                dfs(i, -1, timer, disc, low, result, adj, vis);
            }
        }
        for(auto bridge : result){
            if((bridge[0] == c && bridge[1] == d) || (bridge[0] == d && bridge[1] == c)) {
                return true;  
            }
        }
        return false;  
    }
};