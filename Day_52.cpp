#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* zero;
    Node* one;
};
void insert(int n, Node* root){
    Node* temp = root;
    for(int i = 31; i >= 0; i--){
        int bit = (n >> i) & 1;
        if(bit == 0){
            if(!root->zero){
                root->zero = new Node();
            }
            root = root->zero;
        }else{
            if(!root->one){
                root->one = new Node();
            }
            root = root->one;
        }
    }
}
int findMaxXor(Node* root, int n){
    Node* temp = root;
    int maxXor = 0;
    for(int i = 31; i >= 0; i--){
        int bit = (n >> i) & 1;
        if(bit == 0){
            if(temp->one){
                maxXor |= (1 << i);
                temp = temp->one;
            }else{
                temp = temp->zero;
            }
        }else{
            if(temp->zero){
                maxXor |= (1 << i);
                temp = temp->zero;
            }else{
                temp = temp->one;
            }
        }
    }
    return maxXor;
}
class Solution {
public:
    int maxXor(vector<int> &arr) {
        int n = arr.size();
        Node* root = new Node();
        insert(arr[0], root);
        int result = 0;
        for(int i = 1; i < n; i++){
            int currXor = findMaxXor(root, arr[i]);
            result = max(result, currXor);
            insert(arr[i], root);
        }
        return result;
    }
};
