#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> result(n, -1);
        stack<int> st;
        for(int num : arr){
            freq[num]++;
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && freq[st.top()] <= freq[arr[i]]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }
};