#include <vector>
#include <unordered_map>
#include <stack>
#include<algorithm>
#include <numeric>

using namespace std;  
class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int w, int minH) {
        int n = arr.size();
        vector<int> water(n + 1, 0); 
        int used = 0, curr = 0;

        for(int i = 0; i < n; ++i){
            curr += water[i];
            int height = arr[i] + curr;
            if(height < minH){
                int need = minH - height;
                used += need;
                if(used > k) return false;

                curr += need;
                if(i + w < n) 
                water[i + w] -= need;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end()) + k;
        int res = low;

        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(arr, k, w, mid)){
                res = mid;       
                low = mid + 1;
            }else{
                high = mid - 1;    
            }
        }
        return res;
    }
};