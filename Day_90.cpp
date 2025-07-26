#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leafNodes(vector<int>& preorder){
        vector<int> res;
        int idx = 0;
        helper(preorder, idx, INT_MIN, INT_MAX, res);
        return res;
    }
    void helper(vector<int>& preorder, int& idx, int minVal, int maxVal, vector<int>& res) {
        if(idx >= preorder.size() || preorder[idx] < minVal || preorder[idx] > maxVal)
            return;
        int rootVal = preorder[idx++];
        int startIdx = idx;
        helper(preorder, idx, minVal, rootVal - 1, res);
        helper(preorder, idx, rootVal + 1, maxVal, res);
        if (idx == startIdx)
            res.push_back(rootVal);
    }
};