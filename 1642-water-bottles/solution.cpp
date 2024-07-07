class Solution {
public:
    int numWaterBottles(int n, int e) {
        int ans= n,em=n;
         while(em >=e){
            
            ans += em/e;
            em  = em/e + em%e;
         }
        return ans;
    }
};
