class Solution {
  public:
    int countConsec(int n) {
       
        int x = 1; 
        int y = 1;
        if(n < 2){
            return 0;
        }
        for(int i = 2; i <= n; i++){
            int curr_x = x + y;
            int curr_y = x;
            x= curr_x;
            y = curr_y;
        }
        int validString = x + y; 
        int total = 1 << n; 
        return total - validString; 
    }
};