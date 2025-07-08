#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> result(n, -1); 
        stack<int> st; 
        for(int i = 2 * n - 1; i >= 0; i--){
            int idx = i % n;
            while(!st.empty() && arr[st.top()] <= arr[idx]){
                st.pop();
            }
            if(!st.empty()){
                result[idx] = arr[st.top()];
            }
            st.push(idx);
        }
        return result;
    }
};