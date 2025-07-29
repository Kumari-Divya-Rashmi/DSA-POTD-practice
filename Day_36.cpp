#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntfresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (mat[i][j] == 2){
                    q.push({{i, j}, 0});  
                    vis[i][j] = 2;        
                }
                if(mat[i][j] == 1){
                    vis[i][j] = 1;        
                    cntfresh++;           
                }
            }
        }
        int drow[] = { -1, 0, 1, 0 };
        int dcol[] = { 0, 1, 0, -1 };
        int cnt = 0;  
        int tmCnt = 0;  
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;  
            tmCnt = max(tmCnt, t);  
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 1 && mat[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;  
                    cnt++;  
                }
            }
        }
        if (cnt != cntfresh) return -1;
        return tmCnt;  
    }
};
