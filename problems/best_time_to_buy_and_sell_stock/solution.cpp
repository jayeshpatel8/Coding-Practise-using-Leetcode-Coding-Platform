class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int min,max,p=0;
        min=max=prices[0];
        for (int i=1; i<prices.size(); i++){
            if (prices[i]-min>p)
            {
                p = prices[i]-min;
                max = prices[i];
            }
            else if (prices[i]<min)
                min=prices[i];
        }
        return p;
    }
};