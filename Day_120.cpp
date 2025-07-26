#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        vector<int> freq(26,0);
        for(char c: s){
            freq[c - 'a']++;
        }
        priority_queue<int> pq;
        for(int f : freq){
            if(f > 0){
                pq.push(f);
            }
        }
        while(k-- && !pq.empty()){
            int top = pq.top(); 
            pq.pop();
            if (top > 1) pq.push(top - 1);
        }
        int result = 0;
        while(!pq.empty()){
            int f = pq.top(); 
            pq.pop();
            result += (f * f);
        }
        return result;
    }
};