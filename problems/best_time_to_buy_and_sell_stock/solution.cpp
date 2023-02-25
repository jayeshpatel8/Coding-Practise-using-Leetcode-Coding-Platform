class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 , m = 10000;
        for (auto i : prices){
            ans= max(ans, i - m);
            m = min(m , i);
        }
        return ans;
    }
};