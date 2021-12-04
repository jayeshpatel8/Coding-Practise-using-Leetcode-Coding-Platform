class Solution {
public:
    int dp[41][41][2000];
    int l1,l2;
    bool possiblyEquals(string s1, string s2) {
        l1 = s1.size(), l2 = s2.size();
        memset(dp,-1,sizeof(dp));
        return dfs(s1,s2,0,0,0);
    }
    bool dfs(string &s1, string &s2,  int i,int j, int diff){
        if (i==l1 && j==l2){
            return dp[i][j][diff+1000] = diff==0;
        }
        
        if (dp[i][j][diff+1000] != -1) return dp[i][j][diff+1000];
        
        // char char
        if (diff==0 && i<l1 && j<l2 && s1[i] == s2[j] && dfs(s1,s2,i+1,j+1,diff)){
            return dp[i][j][1000] = true;
        }
        if (diff > 0 && j<l2 && !isdigit(s2[j]) && dfs(s1,s2,i,j+1,diff-1))
            return dp[i][j][diff+1000] = true ;
        if (diff < 0 && i<l1 && !isdigit(s1[i]) && dfs(s1,s2,i+1,j,diff+1))
            return dp[i][j][diff+1000] = true;
        
            
        for (int k=j ,val = 0; k<l2 && isdigit(s2[k]); k++){
            val =val * 10 + s2[k]-'0';
            if (dfs(s1,s2,i,k+1,diff-val))
                return dp[i][j][diff+1000] = true;
        }
            
        for (int k=i, val = 0; k<l1  && isdigit(s1[k]); k++){
            val =val * 10 + s1[k]-'0';
            if (dfs(s1,s2,k+1,j,diff+val))
                return dp[i][j][diff+1000] = true;
        }
        
        return dp[i][j][diff+1000]=false;
    }
};