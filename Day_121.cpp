#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    int getCount(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 10;
        char keypad[4][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}  
        };
        int rowMove[] = {0, 0, -1, 1, 0};
        int colMove[] = {-1, 1, 0, 0, 0};
        vector<vector<long long>> dp(10, vector<long long>(n + 1, 0));
        
        for(int i = 0; i <= 9; i++) dp[i][1] = 1;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 3; j++){
                    if (keypad[i][j] == '*' || keypad[i][j] == '#')
                        continue;
                    int num = keypad[i][j] - '0';
                    for(int k = 0; k < 5; k++){
                        int newRow = i + rowMove[k];
                        int newCol = j + colMove[k];
                        if(newRow >= 0 && newRow < 4 && newCol 
                        >= 0 && newCol < 3 &&
                            keypad[newRow][newCol] != '*' && 
                            keypad[newRow][newCol] != '#'){
                            int nextNum = keypad[newRow][newCol] 
                            - '0';
                            dp[num][len] += dp[nextNum][len - 1];
                        }
                    }
                }
            }
        }
        long long total = 0;
        for (int i = 0; i <= 9; i++)
            total += dp[i][n];
        return total;
    }
};