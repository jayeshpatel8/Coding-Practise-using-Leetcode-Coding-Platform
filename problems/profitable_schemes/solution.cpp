class Solution {
public:
    int mod = 1e9 +7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        if (minProfit == 0) return group.size();
        int dp[101][101]={0}; //{profit, group}
        dp[0][0]=1;
        for (int i=0; i< profit.size(); i++){
            for (int  p=minProfit; p>=0; p--){
                for (int g=n; g>=group[i]; g--){
                    int p0 = min(minProfit, p+profit[i]);
                    dp[p0][g] = (dp[p0][g] + dp[p][g-group[i]]) % mod;
                }
            }
        }
        int ans = 0;
       
        for (int g=0; g<=n; g++){
            ans = (ans + dp[minProfit][g]) % mod;
        }
        
        return ans;
    }
/*    
    int dp[101][101][101] , mod = 1e9 +7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        if (minProfit == 0) return group.size();
        memset(dp,-1,sizeof(dp));
        return schemes(n,minProfit,group,profit, 0);
    }
    int schemes(int n, int minProfit, vector<int>& group, vector<int>& profit, int i){
        if (n<=0) return 0;
        if(i == group.size()) return 0;
        if(dp[i][n][minProfit] != -1) return dp[i][n][minProfit];
        long ans  = 0;        
        // exclude
        ans = (  schemes(n,minProfit,group,profit, i+1));
        // include
        if (group[i] <= n){
            int pro = minProfit-profit[i] <=0 ;
            ans =  (ans + ( pro ) + schemes(n-group[i],pro? 0: minProfit-profit[i],group,profit, i+1));
        }
        
        return dp[i][n][minProfit] = ans % mod;
    }*/
};

/*
1
1
[1,1,1,1,2,2,1,2,1,1]
[0,1,0,0,1,1,1,0,2,2]
*/