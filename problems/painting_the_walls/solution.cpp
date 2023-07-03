class Solution {
public:
int dp[501][501] = {};
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int N =  cost.size();
        function<int(int,int)> dfs = [&](int i, int n)->int{
            if (n <= 0) return 0;
            if (i >= N){
                if (n>0) return 1e9;
                return 0;
            } 
            
            if (dp[i][n]) return dp[i][n];
            int ans =  dfs(i+1,n) -1;
            ans= 1 + min(ans, cost[i] + dfs(i+1,n-time[i]-1)-1);
            return (dp[i][n] =ans );
        };
        return dfs(0,N)  ;
    }
};