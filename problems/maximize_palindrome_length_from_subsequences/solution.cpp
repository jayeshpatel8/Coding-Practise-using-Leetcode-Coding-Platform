class Solution {
public:
    int DP[2001][2001];
    int M;
    int longestPalindrome(string word1, string word2) {
        string s = word1+word2; 
        int N =s.size(), ans=0;;
        M=word1.size();
        for (int i=0; i<N; i++)
            DP[i][i]=1;
        for (int len=1; len<N; len++){
            for (int i=0; i<N-len; i++){
                int j = i+len;
                if (s[i]==s[j]){
                    DP[i][j]= 2 + DP[i+1][j-1];
                    if(i<M && j>=M)
                        ans = max(ans, DP[i][j]);
                }
                else 
                    DP[i][j] = max (DP[i][j-1], DP[i+1][j]);
            }
        }
        
        return ans;
    }
};