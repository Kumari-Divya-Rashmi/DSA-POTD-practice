#include <vector>
#include <unordered_map>
#include <stack>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<char, int> freq;
        string vowels = "aeiou";
        for(char c : s) {
            if(vowels.find(c) != string::npos){
                freq[c]++;
            }
        }
        int uniqueVowels = freq.size();
        if (uniqueVowels == 0) 
           return 0;
        int choices = 1;
        for(auto& pair : freq){
            choices *= pair.second;
        }
        int fact = 1;
        for(int i = 1; i <= uniqueVowels; i++){
            fact *= i;
        }
        return choices * fact;
    }
};