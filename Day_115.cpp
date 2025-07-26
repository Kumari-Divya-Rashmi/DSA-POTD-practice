#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        queue<int> police, thief;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 'P')
                police.push(i);
            else if(arr[i] == 'T')
                thief.push(i);
            while(!police.empty() && !thief.empty()){
                int p = police.front();
                int t = thief.front();
                if(abs(p - t) <= k){
                    count++;
                    police.pop();
                    thief.pop();
                }else if(t < p){
                    thief.pop();
                }else{
                    police.pop();
                }
            }
        }
        return count;
    }
};