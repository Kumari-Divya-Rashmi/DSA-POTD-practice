#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        if (n == 2){
          int d = (arr[1] - arr[0]);
            return arr[1] + d;
        }
        int d1 = arr[1] - arr[0];
        int d2 = arr[2] - arr[1];
        int d3 = (arr[2] - arr[0]) / 2;
        int d;
        if(d1 == d2){
          d = d1;
        }else if(d1 == d3){
          d = d1;
        }else{
          d = d2;
        }
        for(int i = 1; i < n; ++i){
            if(arr[i] - arr[i - 1] != d){
                return arr[i - 1] + d;
            }
        }
        return arr[n - 1] + d;
    }
};


