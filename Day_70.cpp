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
    void Solve(Node* root, int level, vector<int>& ans){
        if(root == NULL) return;
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        Solve(root->left, level + 1, ans);
        Solve(root->right, level + 1, ans);
    }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        Solve(root, 0, ans);
        return ans;
    }
};