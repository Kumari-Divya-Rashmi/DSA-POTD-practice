#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        // Create dummy heads and tails for 0s, 1s, 2s
        Node *zeroD = new Node(0), *oneD = new Node(0), *twoD = new Node(0);
        Node *zero = zeroD, *one = oneD, *two = twoD;

        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Combine all three lists
        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        // Head of new list
        Node* newHead = zeroD->next;

        // Free dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
    }
};
