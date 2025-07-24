#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> countStack;
        stack<string> stringStack;
        string res = "";
        int i = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {
                int count = 0;
                
                while (i < s.size() && isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                countStack.push(count);
            } 
            else if (s[i] == '[') {
               
                stringStack.push(res);
                res = "";
                i++;
            } 
            else if (s[i] == ']') {
                
                string temp = res;
                res = stringStack.top();
                stringStack.pop();

                int repeat = countStack.top();
                countStack.pop();

                while (repeat--) {
                    res += temp;
                }
                i++;
            } 
            else {
                
                res += s[i];
                i++;
            }
        }

        return res;
    }
};