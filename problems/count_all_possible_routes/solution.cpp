class Solution {
public:
    int dp[101][201];
    int fi, mod =  1e9 + 7;
    int countRoutes(vector<int>& l, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        fi=finish;
        return dfs(l,start,fuel);
    }
    int dfs(vector<int>& l, int start, int fuel){        
        if (fuel  == 0) return start == fi;
        if (dp[start][fuel] != -1) return dp[start][fuel];
        int ans = start==fi;
        for ( int i=0; i<l.size(); i++){
            if (i != start) {
                int remfuel = fuel - abs(l[start] - l[i]);
                if (remfuel >= 0){
                    ans = (ans + dfs(l,i,remfuel))%mod;
                }
            }
        }
        return dp[start][fuel] = ans;
    }
};