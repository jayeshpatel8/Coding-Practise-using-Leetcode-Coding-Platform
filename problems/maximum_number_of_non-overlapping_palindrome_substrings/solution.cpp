class Solution {
public:

    int maxPalindromes(string s, int k) {
        if (k==1) return s.size();
        int N = s.size();
        int pal[2001][2001]={};
        for (int len=1; len<=k+1; len++){
            for (int i=0 ,j = i+len-1; j<N; i++,j++){
                if (len<3) {
                    pal[i][j]=s[i]==s[j];
                }
                else{
                    if (s[i]==s[j])
                        pal[i][j]=pal[i+1][j-1];
                }
            }
        }
        vector<int> dp(N+1);
        for (int i=0; i+k<=s.size(); i++){            
            if (pal[i][i+k-1]){
                dp[i+k]=max(dp[i]+1, dp[i+k]);
                i+=k-1;
            }
            else if ( pal[i][i+k]){
                dp[i+k+1]=max(dp[i+k+1], 1 + dp[i]);
                i+=k;
            }
            else            
                dp[i+1] = max(dp[i+1],dp[i]);
        }        
        return *max_element(begin(dp),end(dp));
    }    
};