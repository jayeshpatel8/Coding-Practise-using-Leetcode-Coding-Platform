class Solution {
public:
    int arrangeCoins(int n) {
     
        int l = 1, h = n;
        
        while(l <= h ){
            long  m = l + (h - l) / 2;
            long sum = m * ( m + 1) / 2;
        
            if (sum <= n) l = m + 1;
            else  h = m  - 1;            
        }
        return l - 1;
    }
};