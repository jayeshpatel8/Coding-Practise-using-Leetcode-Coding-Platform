#define ll long long int
#define sz(a) (int)a.size()

class Solution {
    int n, m;
    ll dp[101][101][101];

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = sz(robot);
        m = sz(factory);
        sort(robot.begin(), robot.end()); 
        sort(factory.begin(), factory.end()); 
        memset(dp, -1, sizeof dp);
		
        function<ll (int,int,int)>  dfs = [&]( int i, int j, int lim)->ll {

        if(i >= n) return 0;
        if(j >= m) return 1e10;
		
		// if all robots are repaired then we return 0 
        
        ll &ans = dp[i][j][lim];
        if(ans != -1) return ans;
		
        ans = 1e18; // max initial value

        if(lim > 0) ans = dfs( i + 1, j, lim - 1) + abs(robot[i] - factory[j][0]);

        if(j + 1 < m) ans = min(ans, dfs( i, j + 1, factory[j + 1][1]));
        return ans;
    };
        return dfs( 0, 0, factory[0][1]);
    }
};
