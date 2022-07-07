class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3=s3.size();
        if (l1+l2 != l3) return false;
        vector<bool> dp(l2+1);
        
        for (int i=0; i<=l1; i++){
            for (int j=0; j<=l2; j++){
                if (i==0 && j==0)
                    dp[j]=true;
                else if (i==0 )
                    dp[j] = dp[j-1] && s3[i+j-1] == s2[j-1];
                else if (j==0 )
                    dp[j] = dp[j] && s3[i+j-1] == s1[i-1];
                else 
                    dp[j] = (dp[j-1] && s3[i+j-1] == s2[j-1]) ||  (dp[j] && s3[i+j-1] == s1[i-1]);                
            }
        }
        return dp[l2];
    }
};