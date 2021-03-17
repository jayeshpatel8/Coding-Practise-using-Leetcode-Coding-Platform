class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), buy[n], sell[n];
        buy[0] = -prices[0], sell[0]=0;
        for (int i=1; i<prices.size(); i++  ) 
        {
            buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]-fee);
        }
        return sell[n-1];
    }

};