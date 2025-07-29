#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        unordered_set<int> alredypresent;
        for(int num : arr){
            if(alredypresent.count(num)){
                return num;
            }
            alredypresent.insert(num);
        }
        return -1;
    }
};