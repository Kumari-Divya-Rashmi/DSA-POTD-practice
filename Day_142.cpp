#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
  public:
    long long gcd(long long a, long long b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b){
        return (a / gcd(a, b)) * b;
    }

    long long lcmOfThreeNo(long long a, long long b, long long c){
        return lcm(lcm(a, b), c);
    }
    int lcmTriplets(int n) {
        if(n <= 2) return n;
        long long res = 0;
        if(n % 2 != 0){
            res = lcmOfThreeNo(n, n - 1, n - 2);
        }else{
            res = max(lcmOfThreeNo(n, n - 1, n - 3), 
            lcmOfThreeNo(n - 1, n - 2, n - 3));
        }
        return res;
    }
};