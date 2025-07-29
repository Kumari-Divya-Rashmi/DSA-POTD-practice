// #include <unordered_map>
// #include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() : val(0), neighbors({}) {}
    Node(int _val) : val(_val), neighbors({}) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};
class Solution {
  public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
