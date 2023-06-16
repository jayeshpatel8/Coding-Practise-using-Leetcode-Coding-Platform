int mod = 1e9 +7;
class Solution {
public:
    vector<vector<int>> dp;
    int numOfWays(vector<int>& nums) {
        int n  = nums.size();
        dp.resize(n+1,vector<int>(n+1));
        return dfs(nums) - 1;
    }
    int dfs(vector<int> &nums){
        int n = nums.size();
        
        if (n<=1) return 1;
        vector<int> r,l;
        for (int i=1; i<n; i++)
            if (nums[i] < nums[0]) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        return (((comb(n-1,r.size()) * (long)dfs(l))%mod)*dfs(r))%mod;
    }
    int comb(int m, int n){
        if (n==0 || m==0 || n==m ) return dp[m][n] = 1;
        return (dp[m][n] ? dp[m][n] : dp[m][n]=(comb(m-1,n)+comb(m-1,n-1))%mod); 
    }
};