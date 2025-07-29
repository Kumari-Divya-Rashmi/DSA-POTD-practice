#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    Node* createParentMapping(Node* root, int target, 
    map<Node*, Node*> &nodeToParent, Node* &targetNode){
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data == target){
                targetNode = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }
    int burnTree(Node* targetNode, map<Node*, Node*> &nodeToParent){
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;

        while(!q.empty()){
            int size = q.size();
            bool burnedThisLevel = false;
            for(int i = 0; i < size; i++){
                Node* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    burnedThisLevel = true;
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if(current->right && !visited[current->right]){
                    burnedThisLevel = true;
                    visited[current->right] = true;
                    q.push(current->right);
                }
                Node* parent = nodeToParent[current];
                if(parent && !visited[parent]){
                    burnedThisLevel = true;
                    visited[parent] = true;
                    q.push(parent);
                }
            }
            if(burnedThisLevel) time++;
        }
        return time;
    }
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = NULL;
        createParentMapping(root, target, nodeToParent, targetNode);
        return burnTree(targetNode, nodeToParent);
    }
};