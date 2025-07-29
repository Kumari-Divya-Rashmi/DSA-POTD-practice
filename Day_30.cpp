#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int,int>>temp;
        for(int i = 0; i < n; i++) temp.push_back({start[i],finish[i]});
        auto comp = [&](auto &a, auto &b){
            return a.second < b.second;
        };
        sort(temp.begin(), temp.end(), comp);
        int cnt = 1;
        int currFinish = temp[0].second;
        for(int i = 1; i < n; i++){
            if(temp[i].first > currFinish){
                cnt++;
                currFinish = temp[i].second;
            }
        }
        return cnt;
    }
};
