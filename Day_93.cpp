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
    int findMaxFork(Node* root, int k) {
        // code here
        int result = -1; 
        while(root != NULL){
            if(root -> data > k){
                root = root -> left;
            }else{
                result = root -> data;
                root = root -> right;
            }
        }
        return result;
    }
};