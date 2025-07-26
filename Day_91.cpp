#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cnt = 0;
                for(int col = 0; col < m; col++){
                    if(mat[i][col] == 1 && mat[j][col] == 1){
                        ++cnt;
                        if (cnt >= 2) return true; 
                    }
                }
            }
        }
        return false; 
    }
};