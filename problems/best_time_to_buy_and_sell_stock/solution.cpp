class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mi=prices[0];
        for (int i=1; i<prices.size(); i++){
            int p = prices[i];
            ans = max(ans, p - mi);
            mi = min(mi, p);
        }
        return ans;
    }
};