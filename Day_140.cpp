#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
  public:
    int countNumbers(int n) {
        int maxPrime = sqrt(n) + 1;
        vector<int> primes;
        vector<bool> isPrime(maxPrime, true);
        isPrime[0] = isPrime[1] = false;
        
        for(int i = 2; i * i < maxPrime; i++){
            if(isPrime[i]){
                for(int j = i * i; j < maxPrime; j += i){
                    isPrime[j] = false;
                }
            }
        }
        for(int i = 2; i < maxPrime; i++){
            if (isPrime[i]) primes.push_back(i);
        }
        int count = 0;
        for(int i = 0; i < primes.size(); i++){
            long long val = 1;
            for (int j = 0; j < 8; j++) val *= primes[i];
            if (val <= n) count++;
            else break;
        }
        int totalPrimes = primes.size();
        for(int i = 0; i < totalPrimes; i++){
            for(int j = i + 1; j < totalPrimes; j++){
                long long val = 1LL * primes[i] * primes[i] 
                * primes[j] * primes[j];
                if (val <= n) count++;
                else break;
            }
        }
        return count;
    }
};