#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        unordered_map<int, int> occurrences;
        for(int num : arr){
            occurrences[num]++;
        }
        for(auto &element : occurrences){
            if(element.second == 1) 
            return element.first;
        }
        return -1;
    }
};