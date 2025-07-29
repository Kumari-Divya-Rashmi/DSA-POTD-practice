#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>& image,
        int newColor, int delRow[], int delCol[], int initColor){
            
            ans[row][col] = newColor; 
            for(int i = 0; i < 4; i++){
                int nbrRow = row + delRow[i];
                int nbrCol = col + delCol[i];
                if(nbrRow >= 0 && nbrRow < image.size() &&
                    nbrCol >= 0 && nbrCol < image[0].size() &&
                    image[nbrRow][nbrCol] == initColor &&
                    ans[nbrRow][nbrCol] != newColor){
                    dfs(nbrRow, nbrCol, ans, image, newColor, delRow, delCol, initColor);
                }
            }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        if (initColor == newColor) return image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
         dfs(sr, sc, ans, image, newColor, delRow, delCol, initColor);
        return ans;
    }
};
