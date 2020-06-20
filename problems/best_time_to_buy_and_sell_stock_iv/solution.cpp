class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int  len =prices.size();
        if (len < 2) return 0;
        if (k>= len/2)
        {
            int ret=0;
			for (auto i = 1; i < len; i++)
			{
                if (prices[i] > prices[i - 1]) ret+=prices[i] - prices[i - 1];
			}
            return ret;
		}            
        
        
        vector<vector<int>> dp( k+1, vector<int>(2));
        for (int  i=0; i<=k; i++) {
        dp[i][1]=INT_MIN;
         dp[i][0]=0;
        }
        
        for (int day=0; day<len; day++)
        {
            //dp[j][1] = INT_MIN; dp[j][0]=0;
           
            for (int j=1; j<=k;j++)
            {
                dp[j][0] = std::max(dp[j][0], prices[day] + dp[j][1]);    
                dp[j][1] = std::max(dp[j][1], dp[j-1][0]-prices[day]);
            }
            
        }
        return dp[k][0];
    }
};