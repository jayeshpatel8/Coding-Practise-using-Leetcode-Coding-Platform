class Solution {
public:
long dp[101][101]={};
    int stoneGameII(vector<int>& piles){
        return (accumulate(begin(piles),end(piles),0) + dfs(piles))/2;
    }
    int dfs(vector<int>& piles,int i=0, int m=1) {
       if (i>=piles.size()) return 0;
       if (dp[i][m]) return dp[i][m];

       int x = 1, sum=0 , best=INT_MIN, m2=  2 *m;
  
       for (int j=i ,N = min<int>(piles.size() ,i + m2); j<N; j++,x++){
            sum += piles[j];
            best = max<int>(best, sum - dfs(piles,j+1,max(x,m)));
       }
       
       return dp[i][m]=best;
    }
};