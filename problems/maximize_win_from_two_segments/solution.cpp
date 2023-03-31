class Solution {
public:
    int maximizeWin(vector<int>& pp, int k) {
        vector<int> dp(pp.size()+1);
        int ans = 0;
        for (int r=0,l=0; r<pp.size(); r++){
            for (; pp[r]-pp[l] > k; l++);
            dp[r+1] = max(dp[r],r-l+1);
            ans = max(ans, r-l+1 + dp[l]);
        }
        return ans;
    }
};