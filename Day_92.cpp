#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; 


class Solution {
  public:
    void solve(Node* node, int currLen, int currSum, 
    int &maxLen, int &maxSum){
        if(!node) return;
        currLen += 1;
        currSum += node->data;
        if(!node->left && !node->right){
            if(currLen > maxLen){
                maxLen = currLen;
                maxSum = currSum;
            }else if (currLen == maxLen){
                maxSum = max(maxSum, currSum);
            }
            return;
        }
        solve(node->left, currLen, currSum, maxLen, maxSum);
        solve(node->right, currLen, currSum, maxLen, maxSum);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = 0;
        int maxSum = 0;
        solve(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};

