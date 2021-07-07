class Solution {
public:
    int dp[1001][1001];
    int M,N;
    string shortestCommonSupersequence(string s1, string s2) {
        M= s1.size(); N=s2.size();
        
        for (int i=M; i>=0; i--){
            for (int j=N; j>=0; j--){
                if (i==M) dp[i][j] = N-j;
                else if (j==N) dp[i][j] = M-i;
                else if (s1[i]==s2[j]) dp[i][j] = 1  + dp[i+1][j+1];
                else dp[i][j] = 1 + min (dp[i+1][j],dp[i][j+1]);
            }
        }
        string s;
        int i=0,j=0;
        while (  i<M && j < N){
                if (s1[i] == s2[j]) s.push_back(s1[i]), ++i,++j;
                else if (dp[i+1][j] < dp[i][j+1] ) s.push_back(s1[i]), ++i;
                else  s.push_back(s2[j]), ++j;
        }
        if (i==M )s +=  s2.substr(j);
        if (j==N )s +=  s1.substr(i);
        return s;
    }
    int scs(string & s1, string &s2, int i, int j){
        if (i == M) return N-j;
        if (j == N) return M-i;
        if (dp[i][j] != 0) return dp[i][j];
        if (s1[i]==s2[j]) return dp[i][j]=1 +scs(s1,s2,i+1,j+1);
        return dp[i][j] = 1 + min(scs(s1,s2,i+1,j),  scs(s1,s2,i,j+1));
    }
};