class Solution {
public:
    map<int,int> M[1001];
    int N, T;
    int dp[1001][1001]={} , mod = 1e9 +7;
    int numWays(vector<string>& words, string target) {
        N  = words[0].size();
        T = target.size();
        /*
        for (int i=0; i<words.size(); i++){
            for (int j=0; j<N; j++){
                M[j][words[i][j]-'a']++;
            }
        }*/
        int dp1[1001]={};
        dp1[0]=1;
        for ( int i=1; i<=N; i++){
            int freq[26]={};
            for (int k=0; k<words.size(); k++) freq[words[k][i-1]-'a']++;
            for ( int j=T; j>=1; j--){
                
                int cnt = freq[target[j-1]-'a'];
                if (cnt)
                    dp1[j] = (dp1[j] +dp1[j-1] * (long)cnt )%mod;
            }
        }
        return dp1[T];
        /*
        for ( int i=0; i<=words.size(); i++) dp[i][0]=1;
        for ( int i=1; i<=N; i++){
            for ( int j=1; j<=T; j++){
                int freq = M[i-1][target[j-1]-'a'] , ans = dp[i-1][j];
                if (freq)
                    ans = (ans +dp[i-1][j-1] * (long)freq )%mod;
                dp[i][j] = ans;
            }
        }
        return dp[N][T];
*/
        //memset(dp,-1, sizeof(dp));
        //return dfs(target);
    }
    long dfs(string& target, int i=0, int j=0){
        if (j >= T) return 1;
        if (N-i < T-j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans =dfs(target, i+1,j), freq = M[i][target[j]-'a'];
        if (freq)
            ans = (ans  + freq  * dfs(target, i+1, j+1)) %mod;        
        return dp[i][j] =  ans;
    }
};