#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* succ = NULL;
        Node* curr = root;
        while(curr){
            if (curr -> data < key){
                pre = curr;
                curr = curr -> right;
            }else{
                curr = curr -> left;
            }
        }
        curr = root;
        while(curr){
            if(curr -> data > key){
                succ = curr;
                curr = curr -> left;
            }else{
                curr = curr -> right;
            }
        }
        return {pre, succ};
    }
};
