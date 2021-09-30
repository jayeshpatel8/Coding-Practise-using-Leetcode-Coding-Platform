class Solution {
public:
    int numberOfArrays(string s, int k) {    
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1; 
        int N = s.size(), K=k, mod  =  1e9 + 7;
        for ( int i=s.size()-1; i>=0; i--){
            if (s[i] == '0') continue;
            size_t n =0, ans = 0;
            for (int  j = i; j<N; j++){
                n =  n * 10 + s[j]-'0'; 
                if (n > K) break;   
                ans = (ans + dp[j+1] ) % mod;                                
            }   
            dp[i] = ans;
        }
        return dp[0];
    }
    /*
    int dp[100001] = {}, N , K, mod  =  1e9 + 7;
    int numberOfArrays(string s, int k) {
        N = s.size(); K=k;
        return dfs(s);
    }
    int dfs(string & s, int i = 0){
        if( i >= N) return 1;
        if (s[i] == '0') return 0;
        if (dp[i]) return dp[i];
        size_t n =0, ans = 0;
        for (int  j = i; j<N; j++){
            n =  n * 10 + s[j]-'0'; 
            if (n > K) break;   
            ans = (ans + dfs(s,j+1) ) % mod;                                
        }
        return dp[i] = ans;
    }*/
};