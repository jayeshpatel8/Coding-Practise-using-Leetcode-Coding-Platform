class Solution {
public:
vector<int> dp;
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y)    return y-x;
        dp.resize(10011,-1);
            
        return bfs(x,y);
    }
    int bfs(int x, int y){
        queue<int> q; q.push(x);
        dp[x]=0;
        while (!q.empty() && dp[y]<0){
            int u = q.front(); q.pop();
            int v = u+1;
            if (v<10011 && dp[v]<0){
                dp[v]=dp[u]+1;q.push(v);
            }
            v = u-1;
            if (v >=0 && dp[v]<0){
                dp[v]=dp[u]+1;q.push(v);
            }
            v=u/11;
            if ((u%11 ==0) && dp[v]<0){
                dp[v]=1+dp[u];q.push(v);
            }
            v=u/5;
            if ((u%5 ==0) && dp[v]<0){
                dp[v]=1+dp[u];q.push(v);
            }
        }
        return dp[y];
    }
    int dfs(int x, int y){
        if (x<=y) return y-x;
        if (dp[x]!=-1) return dp[x];
        return dp[x] =1 + min ({
            dfs(x-1, y),
            (11-x %11 ) % 11+ dfs(x/11+ (x%11 >0), y),
            (5-x %5 ) % 5 +dfs(x/5 + (x%5>0),  y)
        });
    }
};
