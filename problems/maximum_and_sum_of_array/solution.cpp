class Solution {
public:
     vector<int> dp;
    int N, S;
    int maximumANDSum(vector<int>& nums, int numSlots ) {
        S=numSlots , N=nums.size();
        
        dp.resize(1<<(numSlots *2),-1);
        
        return dfs(nums,0,0);
    }
    int dfs(vector<int>& nums, int i, int mask){
        if (i >= N) return 0;
        if (dp[mask] !=  -1) return dp[mask];
        int ans = 0;

        for ( int s=0; s<2*S; s+=2){
            int cnt = ((mask >> s) & 3);
            if ( cnt < 2)
                ans = max(ans,( (s/2 + 1) & nums[i]) + dfs(nums,i+1,mask | ((cnt+1)<<s)) );
        }
        return dp[mask] = ans;;
    }
};