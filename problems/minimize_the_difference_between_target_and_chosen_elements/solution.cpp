class Solution {
public:
    int dp[71][70*70+1];
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,-1,sizeof(dp));
        vector<set<int>> v;
        for(auto &i : mat) v.push_back(set(begin(i), end(i)));
        return bt(v,target,0,0);
    }
    int bt(vector<set<int>>& mat, int target, int i, int sum){
        if (i >= mat.size())
            return abs(target - sum) ;
        if(dp[i][sum] != -1) return dp[i][sum];
        int ans = INT_MAX;
        for (auto j : mat[i]){
            ans = min(ans, bt(mat,target,i+1,sum+j));
            if(ans == 0)
                return dp[i][sum] = 0;
        }
        
        return dp[i][sum] = ans;
    }
};