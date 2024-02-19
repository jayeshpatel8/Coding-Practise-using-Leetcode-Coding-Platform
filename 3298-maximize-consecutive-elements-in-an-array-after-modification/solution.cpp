class Solution {
public:
     int maxSelectedElements(vector<int>& A) {
        unordered_map<int, int> dp;
        sort(A.begin(), A.end());
        
        for (int& a : A) {
            
            dp[a + 1] = dp[a] + 1;
            dp[a] = dp[a - 1] + 1;
            
        }
        int ans = 1;
        for (auto &[k,v] : dp) ans= max(ans, v);
        return ans;
    }
};
