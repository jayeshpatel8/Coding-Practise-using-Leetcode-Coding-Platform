class Solution {
public:
int dp[15][0b11111111111111];
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        int n  = nums.size()/2;
        vector<vector<int>> gcd(n*2,vector<int>(n*2));
        for (auto i=0; i<nums.size(); i++)
            for (auto j=0; j< nums.size(); j++) 
                gcd[i][j] = __gcd(nums[i], nums[j]);
        function<int(int , int)> dfs =[&](int i, int mask)->int {
            if (i>n)             
                return 0;
            
            if (dp[i][mask] != -1) return dp[i][mask];
            int ret=0;
            for (int j1=0;j1<2*n; j1++){
                if (mask & (1<<j1)) continue;    
                auto new_mask = mask | (1<<j1);            
                for (int j2=j1+1;j2<2*n; j2++){
                    if (new_mask & (1<<j2)) continue;
                    ret = max(ret, i*gcd[j1][j2] + dfs(i+1,new_mask | (1<<j2)));

                }
            }
            
            return dp[i][mask]= ret;
        };
        return dfs(1,0);
    }
};