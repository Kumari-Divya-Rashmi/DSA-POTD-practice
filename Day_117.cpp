#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string minSum(vector<int> &arr) {
       sort(arr.begin(), arr.end());
       string num1 = "", num2 = "";
       for(int i = 0; i < arr.size(); i++){
          if(i % 2 == 0)
            num1 += to_string(arr[i]);
          else
            num2 += to_string(arr[i]);
        }
        return addStrings(num1, num2);
    }
    string addStrings(string a, string b){
       string result = "";
       int carry = 0, i = a.length() - 1, j = b.length() - 1;
       while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
              result += (sum % 10) + '0';
              carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        int pos = result.find_first_not_of('0');
        if (pos != string::npos)
           return result.substr(pos);
        else
           return "0";
   }
};