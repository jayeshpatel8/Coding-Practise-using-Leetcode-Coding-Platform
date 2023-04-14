class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        for (auto c : s){
            int ans = 0;
            for (int i= max(0,c-'a'-k) , N=  min(25,c-'a'+k)+1; i<N; i++ )
                ans = max(ans,dp[i]);
            dp[c-'a'] = max(dp[c-'a'], 1 + ans);
        } 
        return *max_element(begin(dp),end(dp));
    }
};