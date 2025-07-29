#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    void dfs(Node* root, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;

        path.push_back(root->data);
        if (!root->left && !root->right) {
            result.push_back(path);
        } else {
            dfs(root->left, path, result);
            dfs(root->right, path, result);
        }

        path.pop_back(); 
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }
};
