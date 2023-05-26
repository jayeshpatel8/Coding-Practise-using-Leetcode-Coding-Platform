

class Solution {
public:
unordered_map<int,int> dp;
    int minDays(int n) {        
        return dfs(n);
    }

    int dfs(int n){
        
        if (n <=1 ) return n;
        if (dp.count(n)==0) 
            dp[n] =  1 + min(n%2 + dfs(n/2), n%3 + dfs((n/3)));
        
        return dp[n]  ;
    }
};