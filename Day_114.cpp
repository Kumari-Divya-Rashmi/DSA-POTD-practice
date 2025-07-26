#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        if (arr.size() % k != 0){
            return false;
        }    
        map<int, int> freq;
        for (int num : arr){
            freq[num]++;
        }    
        while(!freq.empty()){
            int start = freq.begin() -> first;
            for(int i = 0; i < k; i++){
                int current = start + i;
                if(freq[current] == 0){
                    return false;
                }    
                freq[current]--;
                if(freq[current] == 0){
                    freq.erase(current);
                }    
            }
        }
        return true;
    }
};