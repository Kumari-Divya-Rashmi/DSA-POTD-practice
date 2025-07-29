#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        // Directions: up, down, left, right, and 4 diagonals
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        grid[i][j] = 'W'; // Mark as visited

        for (int d = 0; d < 8; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 'L') {
                dfs(grid, ni, nj, n, m);
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L') {
                    dfs(grid, i, j, n, m);
                    count++;
                }
            }
        }

        return count;
    }
};
