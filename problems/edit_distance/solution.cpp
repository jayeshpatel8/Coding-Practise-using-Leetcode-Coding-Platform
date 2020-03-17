class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1=word1.size(),l2=word2.size();
        if (l1==0 ) return l2;
        if (l2==0 ) return l1;
     
        vector<int> dp(l2+1,0);        
        for (int j=0; j<=l2; j++)
            dp[j]=j;        
        for (int i=0; i<l1; i++){
            int prev = dp[0];
            dp[0]=i+1;
            for (int j=0; j<l2; j++)    {
                int t = dp[j+1];
                if (word1[i]==word2[j])
                    dp[j+1]=prev;
                else
                    dp[j+1]=1+min(min(dp[j+1],dp[j]),prev);
                prev=t;
            }
        }
#if 0        
        vector<int> dp(l1+1,vector<int>(l2+1,0));           
        for (int i=0; i<=l1; i++)
            dp[i][0]=i;
        for (int j=0; j<=l2; j++)
            dp[0][j]=j;
        for (int i=0; i<l1; i++)
            for (int j=0; j<l2; j++){
                if (word1[i]==word2[j])
                    dp[i+1][j+1]=dp[i][j];
                else
                    dp[i+1][j+1]=1+min(min(dp[i][j+1],dp[i][j]),dp[i+1][j]);
            }
#endif        
        return dp[l2];
    }
};

// hhorse
// avnjrjwkhorse