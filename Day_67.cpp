#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
   bool isPrime(int n){
       if(n <= 1) return false;
       if(n == 2) return true;
       if(n % 2 == 0) return false;
       for( int i = 3; i * i <= n; i += 2){
           if(n % i == 0)
            return false; 
       }
       return true;
   }
   int nearestPrime(int n){
        if(isPrime(n)) return n;
        int prev = n - 1;
        int next = n + 1;
        while(true){
           if(prev >= 2 && isPrime(prev)) return prev;
           if(isPrime(next)) return next;
           --prev;
           ++next;
        }
   }
    Node *primeList(Node *head) {
        // code here
        Node *temp  = head;
        while(temp != 0){
            temp -> val = nearestPrime(temp -> val);
            temp = temp -> next;
            
        }
        return head;
    }
};