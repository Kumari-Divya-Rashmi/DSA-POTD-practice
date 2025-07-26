#include <climits>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    struct Node *left, *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool solve(Node* root, int minVal, int maxVal) {
        if (!root) return false;
        if (minVal == maxVal) return true;

        return solve(root->left, minVal, root->data - 1) ||
               solve(root->right, root->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return solve(root, 1, INT_MAX);
    }
};
