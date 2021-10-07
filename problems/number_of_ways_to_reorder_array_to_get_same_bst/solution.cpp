class Solution {
public:
    int mod = 1e9 +7;
    //vector<vector<int>> dp;
    int dp[1001][1001]={};
    int numOfWays(vector<int>& nums) {
		int n = nums.size();
        /*
		// Pascal triangle        
        dp.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            dp[i] = vector<int>(i + 1, 1);
            cout<< dp[i][0] << " ";
            for(int j = 1; j < i; ++j){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                cout<< dp[i][j] << " ";
            }
            cout<< endl;
        } */       
        return dfs(nums)-1;
    }
    int dfs(vector<int> nums){
        if (nums.size() <=1) return 1;
        vector<int> l,r;
        int  N = nums.size();
        for ( int i=1; i<N; i++){
            if (nums[i] < nums[0]) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }
        // chose r = l.size or r.size from N-1 position
        //return ((dp[N-1][r.size()] * (long)dfs(l))%mod * dfs(r))%mod;
        return ((comb(N-1,r.size()) * (long)dfs(l))%mod * dfs(r))%mod;
    }
    int comb(int n, int m) {
        return n == 0 || m == 0 || n==m ? 1 :
            dp[n][m] ? dp[n][m] : 
                dp[n][m] = (comb(n - 1, m) + comb(n-1, m - 1)) % 1000000007;
    }
};