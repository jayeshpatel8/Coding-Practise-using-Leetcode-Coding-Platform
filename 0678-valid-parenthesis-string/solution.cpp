class Solution {
public:
int dp[100][100];
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        for (auto &c : s){
            if (c=='(')  c = 1;
            else if (c==')')  c = -1;
            else c = 2;
        }
        return dfs(s,0);
    }
    bool dfs(string &s , int i, int cnt = 0) {
      if (i >= s.size()|| cnt < 0) return cnt==0;
        if (dp[i][cnt] >= 0) return dp[i][cnt];
        bool ans = false;
        if (s[i]<2) ans =dfs(s,i+1,cnt+s[i]);        
        else 
            ans =dfs(s,i+1,cnt+1) || dfs(s,i+1,cnt-1) || dfs(s,i+1,cnt);        

      return dp[i][cnt] =ans;;  
    }
};
/*
((*)))
*/
