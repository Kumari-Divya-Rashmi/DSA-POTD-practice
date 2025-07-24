#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        const int MAX = 10000;
        std::vector<int> freq(MAX + 1, 0);
        for(int num : arr){
            freq[num]++;
        }
        std::vector<int> f(MAX + 1, 0);
        for(int i = 1; i <= MAX; ++i){
            for(int j = i; j <= MAX; j += i){
                f[i] += freq[j];
            }
        }
        std::vector<int> mu(MAX + 1, 1);
        std::vector<bool> is_prime(MAX + 1, true);
        for(int i = 2; i <= MAX; ++i){
            if(is_prime[i]){
                for(int j = i; j <= MAX; j += i){
                    mu[j] *= -1;
                    is_prime[j] = false;
                }
                for(long long j = 1LL * i * i; j <= MAX; j += 1LL * i * i){
                    mu[j] = 0;
                }
            }
        }
        long long result = 0;
        for(int d = 1; d <= MAX; ++d){
            if(f[d] >= 2){
                result += 1LL * mu[d] * f[d] * (f[d] - 1) / 2;
            }
        }
        return (int)result;
    }
};
