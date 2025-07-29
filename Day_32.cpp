#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int total_tank = 0, curr_tank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int balance = gas[i] - cost[i];
            total_tank += balance;
            curr_tank += balance;

            if (curr_tank < 0) {
                start = i + 1;
                curr_tank = 0;
            }
        }

        return (total_tank >= 0) ? start : -1;
    }
};
