#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    int countNodesinLoop(Node *head) {
        std::unordered_set<Node*> vis;
        Node* curr = head;

        while(curr){
            if (vis.find(curr) != vis.end()){
               
                Node* loop_start = curr;
                int count = 1;
                curr = curr->next;
                while(curr != loop_start){
                    count++;
                    curr = curr->next;
                }
                return count;
            }
            vis.insert(curr);
            curr = curr->next;
        }
        return 0; 
    }
};    