class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue, int i=0) {
        int N = stoneValue.size();
        vector<int> dp(N+1);
        function<int(int)> dfs = [&](int i)->int{
            if (i >=  N) return 0;
            if (dp[i]) return dp[i];
            int ans = INT_MIN, sum = 0;
            for (int j=i; j< N && j<i+3;j++){
                sum += stoneValue[j];
                ans= max(ans, sum - dfs(j+1));
            }
            return dp[i]=ans;
        };
        //int ans = dfs(0) ;
        //return ans==0? "Tie" : (ans > 0 ? "Alice" : "Bob"); 
        for ( int i=N-1; i>=0; i--){
            int sum = stoneValue[i];            
            dp[i]=sum-dp[i+1];            
            
            if (i+2<N){
                sum +=stoneValue[i+1];
                dp[i] =max(dp[i], sum - dp[i+2]);
                dp[i] =max(dp[i], sum +stoneValue[i+2] - dp[i+3]);            
            }
            else if (i+1<N){
                sum +=stoneValue[i+1];
                dp[i] =max(dp[i], sum - dp[i+2]);
            }
        }
 
        return dp[0]==0? "Tie" : (dp[0] > 0 ? "Alice" : "Bob"); 
    }
};