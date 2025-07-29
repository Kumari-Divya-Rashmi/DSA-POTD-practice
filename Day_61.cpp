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
   
    pair<int, int> solve(Node* root) {
        if (!root) return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);
        int include = root->data + left.second + right.second;
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }

    int getMaxSum(Node *root) {
        auto res = solve(root);
        return max(res.first, res.second);
    }
};
