class Solution {
public:
     int mod = (int)1e9 +7;
    int dp[31][1001];
    int numRollsToTarget(int d, int f, int target) {
      memset(dp,-1,sizeof(dp));
        return roll(d,f,target);
    }
    int roll(int d, int f, int target){
        if(d == 0 || target < 0)
            return target == 0   ;  
        
        if (dp[d][target] != -1) return dp[d][target];
        int ans=0;
        for (int face=1; face <=f; face++){
            if ( target >= face)
                ans =(ans+ roll(d-1,f,target-face))%mod;
        }
        return dp[d][target] = ans ;
        
    }
    /**
    int numRollsToTarget(int d, int f, int target) {
        int mod = (int)1e9 +7;
        vector<int> ways(target+1);
        ways[0]=1;        
        for (int rep = 1; rep <= d; ++rep) {
           vector<int> new_ways(target+1);
           for (int already = 0; already <= target; ++already) {
               for (int pipe = 1; pipe <= f; ++pipe) {
                   if (already - pipe >= 0) {
                       new_ways[already] += ways[already - pipe];
                       new_ways[already] %= mod;
                   }
               }
           }
           ways = new_ways;
        }
        return ways[target];
    }
    */
};

