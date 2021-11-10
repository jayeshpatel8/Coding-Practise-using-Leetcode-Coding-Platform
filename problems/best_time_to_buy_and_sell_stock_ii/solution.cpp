class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = prices[0],buy = prices[0]; 
        long ans = 0 ;
        
        for ( int i=1; i<prices.size(); i++ ){
            sell = prices[i];
            int diff = sell - buy;
            if (diff > 0)
                ans += diff;
            buy = sell;
        }
        return ans;
    }
};