class Solution {
public:
int dp[101] = {};
    int numDecodings(string s) {
        return dfs(s,0);
    }
    int dfs(string &s, int i){
        if (i >= s.size()) return 1;
        if (dp[i]) return dp[i];
        int ans = 0;
        if (s[i] != '0'){
          ans = dfs(s,i+1);
          if (i +1 < s.size() ){
              int num = (s[i]-'0') * 10 + (s[i+1]-'0') ;
              if (num <= 26)
                ans += dfs(s,i+2);
          }
        }
        return dp[i] = ans;
    }
};
