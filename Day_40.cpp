#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkCycleFound(int node,unordered_map<int,bool>&visited, 
        unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>& adj){
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto neighbour : adj[node]){
           if(!visited[neighbour]){
                bool cycleDetected = checkCycleFound(neighbour, visited, dfsVisited, adj);
                if(cycleDetected){
                    return true;
                }
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];  
            int v = edges[i][1];  
            adj[u].push_back(v);
        }
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        
        for (int i = 0; i < V; i++){
            if (!visited[i]){
                bool cycleFound = checkCycleFound(i, visited, dfsVisited, adj);
                if (cycleFound){
                    return true;
                }
            }
        }
        return false;
    }
};
