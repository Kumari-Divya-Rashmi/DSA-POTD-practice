#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(), words.end());
        unordered_set<string> validWords;
        string result = "";

        for(const string &word : words) {
            if(word.size() == 1 || validWords.count
             (word.substr(0, word.size() - 1))){
                validWords.insert(word);
                if (word.size() > result.size() || 
                    (word.size() == result.size() && word < result)){
                    result = word;
                }
            }
        }return result;
    }
};