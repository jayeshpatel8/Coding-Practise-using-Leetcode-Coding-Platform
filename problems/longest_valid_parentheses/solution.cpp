class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0 , n =s.size();
        if (n==0 ) return 0;
        vector<int> dp(n+1), st;
        
        for (int i=1; i<=n; i++){
            if (s[i-1] =='('){
                st.push_back(i);
            }
            else{
                if (!st.empty()){
                    int j = st.back();st.pop_back();
                    dp[i] = i-j+1 + dp[j-1];
                    ans = max(ans,dp[i]);
                }                
            }
        }
        return ans;
    }
};