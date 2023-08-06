class Solution {
public:
    long N,L,K,mod = 1e9 + 7;
    int dp[101][101];
    int numMusicPlaylists(int n, int goal, int k) {
        N = n, L=goal,K=k;
        memset(dp,-1,sizeof(dp));
        return lists(0,0);
    }
    int lists(int i, int listlen){
        if (listlen == L) return i == N;
        if (dp[i][listlen] != -1) return dp[i][listlen];
        long ans =  ((lists(i+1,listlen+1) * (N - i) )%mod);
        if ( i > K) // repeat
            ans +=(lists(i,listlen+1) * (i - K) )%mod;
        
        return dp[i][listlen] = ans%mod;
    }
};