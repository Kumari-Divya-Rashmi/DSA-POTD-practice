#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int> result;
        if (!root) return result;
        stack<Node*> s1; 
        stack<Node*> s2; 
        s1.push(root);
        while (!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                Node* node = s1.top();
                s1.pop();
                result.push_back(node->data);
                if (node->right) s2.push(node->right);
                if (node->left) s2.push(node->left);
            }
            while(!s2.empty()){
                Node* node = s2.top();
                s2.pop();
                result.push_back(node->data);
                if (node->left) s1.push(node->left);
                if (node->right) s1.push(node->right);
            }
        }
        return result;
    }
};
