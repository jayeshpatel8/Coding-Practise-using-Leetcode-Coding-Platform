class Solution {
public:
    int dp[103][103]={};
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0),cuts.push_back(n);
        sort(begin(cuts),end(cuts));
        return dfs(cuts,0,cuts.size()-1);
    }
    int dfs(vector<int>& cuts, int i, int j){
        if (j-i <= 1) return 0;
        if (dp[i][j]) return dp[i][j];
        int ans =  INT_MAX;
        for ( int k = i+1; k<j; k++)
            ans = min(ans, cuts[j] - cuts[i] + dfs(cuts,i,k) + dfs(cuts,k,j));
        return dp[i][j] = ans;
    }
};