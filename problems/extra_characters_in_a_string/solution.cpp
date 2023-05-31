class Solution {
public:
int dp[51]={}, N;
unordered_set<string> st;
    int minExtraChar(string s, vector<string>& dict) {
        N = s.size();
        memset(dp,-1,sizeof(dp));
        for (auto &s : dict) st.insert(s);
        return dfs(s, 0);        
    }
    int dfs(string &s , int i){
        
        if (i >= N) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = 1 + dfs(s,i+1);
        string s1;
        for (int j=i ; j< N; j++){
            s1 +=s[j];      
            if (st.count(s1))      
                ans = min(ans, dfs(s,j+1));
        }
        return dp[i] =ans;
    }
};