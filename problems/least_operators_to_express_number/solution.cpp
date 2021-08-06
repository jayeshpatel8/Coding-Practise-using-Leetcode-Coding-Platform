class Solution {
public:
    unordered_map<int, int> dp;
    int x;
    int leastOpsExpressTarget(int X, int target){
        x=X;
        return dfs(target);
    }
    int dfs(int t){
        if (x > t) 
            return min(t * 2 - 1, (x - t) * 2);
        
        if(t==x) return 0;
        if(dp.count(t) ) return dp[t];
               
        long  n=x; int cnt=0;
        while(n < t)
            cnt++, n *= x;
        
        if(n == t) return dp[t] = cnt ;
         int ans = INT_MAX;
        if (n - t < t) 
            ans = min({ans, dfs(n - t)});
        
        ans = min({ans, dfs(t-(n/x))-1});
        
        return dp[t] =  ans + cnt + 1;;
    }

};