class Solution {
public:
    long long minIncrementOperations(vector<int>& n, int k) {
           vector<long> dp(3);
        for (int i = 0; i < n.size(); ++i) {
            auto dp1 = max(0,k-n[i]) + *min_element(begin(dp),end(dp));
            dp[0]=dp[1];
            dp[1]=dp[2];
            dp[2]=dp1;
        }
        return *min_element(begin(dp), end(dp));       
    }
};