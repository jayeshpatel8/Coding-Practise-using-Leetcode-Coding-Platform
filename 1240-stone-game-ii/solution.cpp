class Solution {
public:
    int dp[101][101]= {};
    int stoneGameII(vector<int>& piles) {
        return (accumulate(begin(piles), end(piles),0) + dfs (piles,0))/2;
    }
    
    int dfs(vector<int>& piles, int i, int m=1){
        if (i >= piles.size()) return 0;
        if (dp[i][m]) return dp[i][m];
        int sum=  0, best = INT_MIN;
        for (int j=i,x=1, N= min<int>(piles.size() , i + 2*m); j<N; x++,j++){
            sum += piles[j];
            best = max(best, sum - dfs(piles, j+1, max(m,x)));
        }
        return dp[i][m] = best;
    }
};
