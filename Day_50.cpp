#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w); 
        }
        int minCycle = INT_MAX;
        for (int src = 0; src < V; ++src) {
            vector<int> dist(V, INT_MAX);
            vector<int> parent(V, -1);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[src] = 0;
            pq.push(make_pair(0, src));
            
            while (!pq.empty()) {
                pair<int, int> top = pq.top();
                pq.pop();
                int d = top.first;
                int u = top.second;

                for (size_t i = 0; i < adj[u].size(); ++i) {
                    int v = adj[u][i].first;
                    int w = adj[u][i].second;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        parent[v] = u;
                        pq.push(make_pair(dist[v], v));
                    }
                    else if (parent[u] != v && parent[v] != u) {
                        minCycle = min(minCycle, dist[u] + dist[v] + w);
                    }
                }
            }
        }
        if(minCycle == INT_MAX) return -1;
        else return minCycle;
    }
};