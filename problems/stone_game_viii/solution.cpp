class Solution {
public:
    int n  ;
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();        
        partial_sum(begin(stones), end(stones), begin(stones));
        int ans = stones[n-1];
        for  (int i = n-2; i>0; i-- ){
            ans = max(ans, stones[i] - ans);
        }
        return ans;
    }
    /*
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> dp(n,INT_MIN);
        partial_sum(begin(stones), end(stones), begin(stones));       
        
        return dfs(stones,1,dp); // start from 1 as  x > 1
    }
    int dfs(vector<int> &psum, int i, vector<int> &dp){
        if ( i == n-1) return psum[i];
        if (dp[i] != INT_MIN) return dp[i];
        
        return dp[i] = max(dfs(psum,i+1,dp), psum[i] - dfs(psum,i+1,dp) );
    }*/
};