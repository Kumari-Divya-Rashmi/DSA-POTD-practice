#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, int parent, vector<int> &disc, vector<int> &low, 
             unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, 
             vector<int> &ap, int &timer){
        
        vis[node] = true;
        disc[node] = low[node] = timer++;  
        
        int children = 0;
        for (auto nbr : adj[node]){
            if (nbr == parent) continue; 
            if (!vis[nbr]) {  
                dfs(nbr, node, disc, low, vis, adj, ap, timer);
                low[node] = min(low[node], low[nbr]);  
                if (low[nbr] >= disc[node] && parent != -1){
                    ap[node] = 1;  
                }
                children++;
            }else{
                low[node] = min(low[node], disc[nbr]);
            }
        }
        if (parent == -1 && children > 1){
            ap[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);  
        }
        vector<int> disc(V, -1);  
        vector<int> low(V, -1);   
        unordered_map<int, bool> vis;  
        vector<int> ap(V, 0); 
        
        int timer = 0;  
        for(int i = 0; i < V; i++){
            if (!vis[i]) {
                dfs(i, -1, disc, low, vis, adj, ap, timer);
            }
        }
        vector<int> result;
        for(int i = 0; i < V; i++){
            if(ap[i] == 1){
                result.push_back(i);
            }
        }
        if (result.empty()){
            result.push_back(-1);
        }
        return result;
    }
};