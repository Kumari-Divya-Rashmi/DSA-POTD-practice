#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
  public:
   int evaluate(vector<string>& arr) {
    stack<int> st;

    for (int i = 0; i < arr.size(); i++) {
        const string& str = arr[i];

        if (str == "+" || str == "-" || str == "*" || str == "/") {
            int y = st.top(); st.pop();
            int x = st.top(); st.pop();

            int result = 0;
            if (str == "+") {
                result = x + y;
            } else if (str == "-") {
                result = x - y;
            } else if (str == "*") {
                result = x * y;
            } else if (str == "/") {
                result = x / y; 
            }

            st.push(result);
        } else {
            st.push(stoi(str));
        }
    }

    return st.top();
  }
};