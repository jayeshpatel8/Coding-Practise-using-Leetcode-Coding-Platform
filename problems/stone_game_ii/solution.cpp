class Solution {
public:
    int dp[101][101];
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return (accumulate(begin(piles), end(piles),0)  + dfs(piles, 0, 1))/2;
    }
    int dfs(vector<int>& piles, int i, int m, int alice=1){
        if (i>= piles.size()) return 0;
        if(m > piles.size()) m = piles.size();
        if(dp[i][m] != -1)  return dp[i][m];
        
        int M = 2*m, ans = INT_MIN;
        long sum = 0;
        for (int j = i, x= 1; x<= M && j<piles.size(); j++,x++){
            sum += piles[j];
            ans  = max<long>(ans , sum - dfs(piles, j+1, (max(m, x ))));
        }
        return dp[i][m] =ans;
    }
};