class Solution {
public:
    int jump(vector<int>& nums) {
        size_t l = nums.size() ;
        if (l==1) return 0;
        vector<int> dp(l+1,1);
        dp[0] = 0;
        size_t jump=1;
       
        for (int i = 0 ; i <l; i++){
            
            if (i + nums[i] >= jump)
            {
                while(jump<=nums[i]+i)
                {
                    dp[jump++]=dp[i]+1;
                    if (jump==l) return dp[jump-1];
                }
            }
        }
        return 0;
    }
};