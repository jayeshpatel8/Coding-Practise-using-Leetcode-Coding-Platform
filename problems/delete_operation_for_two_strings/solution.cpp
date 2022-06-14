class Solution {
public:
    vector<vector<int>> dp;
    int l1,l2;
     int minDistance(string word1, string word2) {        
        l1 =word1.size(),l2=word2.size();
        vector<int> dp2(l2+1) ,dp1(dp2);
        
         for (int i=0; i<=l1; i++){
             dp2[0] = i;
             for (int j=1; j<=l2;j++){
                 if (i==0) dp2[j] = j;
                 else {
                     if (word1[i-1] ==word2[j-1])
                         dp2[j] = dp1[j-1];
                     else 
                         dp2[j] = 1 + min(dp1[j],dp2[j-1]);
                 }
             }
             dp1.swap(dp2);
         }
         return dp1[l2];
    }
    int minDistance2(string word1, string word2) {        
        l1 =word1.size(),l2=word2.size();
        dp.resize(l1, vector<int>(l2,-1));
        return dfs(word1,word2,0,0);
    }
    int dfs(string& w1, string& w2,int i, int j){
        if (i == l1) return l2 - j;
        else if (j == l2) return l1 - i;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if (w1[i] != w2[j]){
            ans = min(ans, 1 + dfs(w1,w2,i+1,j));
            ans = min(ans, 1 + dfs(w1,w2,i,j+1));
            ans = min(ans, 2 + dfs(w1,w2,i+1,j+1));
        }
        else
            ans = dfs(w1,w2,i+1,j+1);
        return dp[i][j] = ans;
        
    }
};