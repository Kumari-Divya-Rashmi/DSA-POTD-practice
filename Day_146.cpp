#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        unordered_set<int> s;
        for(int num : arr){
            if(num > 0){
              s.insert(num);
            } 
        }
        int i = 1;
        while(true){
            if(s.find(i) == s.end()){
              return i; 
            } 
           i++;
        }
    }
};