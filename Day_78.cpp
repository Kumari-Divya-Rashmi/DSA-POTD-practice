#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if (n == 1) return "1";
        string currentRow = "1";
        for(int i = 1; i < n; ++i){
        string nextRow = "";
        int count = 1;
        for(size_t j = 1; j <= currentRow.length(); ++j){
            if(j < currentRow.length() && currentRow[j] == currentRow[j - 1]) {
                ++count;
            }else{
                nextRow += to_string(count) + currentRow[j - 1];
                count = 1;
            }
        }
        currentRow = nextRow;
    }
    return currentRow;
    }
};