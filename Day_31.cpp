#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++){
            jobs.push_back({deadline[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        priority_queue<int> maxHeap;
        int totalProfit = 0, jobscnt = 0;
        for(int i = n - 1; i >= 0; i--){
            int availableSlots;
            if(i == 0){
              availableSlots = jobs[i].first;
            }else{
                availableSlots = jobs[i].first - jobs[i - 1].first;
            }
            maxHeap.push(jobs[i].second);
            while (availableSlots-- && !maxHeap.empty()){
                totalProfit += maxHeap.top();
                maxHeap.pop();
               jobscnt++;
            }
        }
        return {jobscnt, totalProfit};
    }
};
        