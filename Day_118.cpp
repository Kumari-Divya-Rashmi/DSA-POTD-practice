#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        string st;
        for(char c : s){
            while(k > 0 && !st.empty() && st.back() < c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        st.resize(st.size() - k);
        return st;
    }
};
