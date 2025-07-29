#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, set<char>> adj;
        unordered_map<char, int> inDegree;

        // Initialize in-degree for all characters
        for (const auto& word : words) {
            for (char c : word) {
                inDegree[c] = 0;
            }
        }

        // Build graph edges from adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());

            bool found = false;
            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].insert(w2[j]).second) {
                        inDegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }

            // Invalid case: prefix issue like ["abc", "ab"]
            if (!found && w1.size() > w2.size()) return "";
        }

        // Topological Sort using Kahn's Algorithm
        queue<char> q;
        for (auto it = inDegree.begin(); it != inDegree.end(); ++it) {
            if (it->second == 0) {
                q.push(it->first);
            }
        }

        string order;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            order += c;

            for (char neighbor : adj[c]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return (order.size() == inDegree.size()) ? order : "";
    }
};
