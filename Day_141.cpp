#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
  public:
    int maxKPower(int n, int k) {
       map<int, int> factors;
        for(int i = 2; i * i <= k; i++){
            while(k % i == 0){
                factors[i]++;
                k /= i;
            }
        }
        if(k > 1){
            factors[k]++;
        }
        int minPower = INT_MAX;
        for(auto it = factors.begin(); it != factors.end(); ++it){
            int prime  = it->first;
            int exponent = it->second;
            int count = 0;
            int power = prime;
            while(power <= n){
                count += n / power;
                if(power > n / prime) break; 
                power *= prime;
            }
            minPower = min(minPower, count / exponent);
        }
        return minPower;
    }
};