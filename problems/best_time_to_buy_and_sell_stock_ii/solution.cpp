class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        int profit = 0;
        for (int j=1; j <len; j++)
        {
            int d = prices[j] - prices[j-1];
            if (d > 0)
                profit +=d;
        }
        return profit;
    }
};