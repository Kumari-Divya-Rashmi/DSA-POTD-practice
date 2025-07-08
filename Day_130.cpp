#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        priority_queue<tuple<int, int, int>> maxHeap;
        set<pair<int, int>> visited;
        maxHeap.push(make_tuple(a[0] + b[0], 0, 0));
        visited.insert({0, 0});
        vector<int> result;
        while(k-- && !maxHeap.empty()){
            auto top = maxHeap.top();
            maxHeap.pop();
            int sum = std::get<0>(top);
            int i = std::get<1>(top);
            int j = std::get<2>(top);
            result.push_back(sum);
            if(i + 1 < n && visited.find({i + 1, j}) 
            == visited.end()){
                maxHeap.push(make_tuple(a[i + 1] + b[j], i + 1, j));
                visited.insert({i + 1, j});
            }
            if(j + 1 < n && visited.find({i, j + 1}) == 
             visited.end()){
                maxHeap.push(make_tuple(a[i] + b[j + 1], i, j + 1));
                visited.insert({i, j + 1});
            }
        }
        return result;
    }
};
