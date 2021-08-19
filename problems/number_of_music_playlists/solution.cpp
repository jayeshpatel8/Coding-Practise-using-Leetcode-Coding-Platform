class Solution {
public:
    long N,L,K,mod = 1e9 + 7;
    int dp[101][101];
    int numMusicPlaylists(int n, int goal, int k) {
        N = n, L=goal,K=k;
        memset(dp,-1,sizeof(dp));
        return lists(0,0);
    }
    int lists(int n, int listlen){
        if (listlen == L) return n == N;
        if (dp[n][listlen] != -1) return dp[n][listlen];
        long ans =  ((lists(n+1,listlen+1) * (N - n) )%mod);
        if (n>K) 
            ans +=(lists(n,listlen+1) * (n - K) )%mod;
        
        return dp[n][listlen] = ans%mod;
    }
};