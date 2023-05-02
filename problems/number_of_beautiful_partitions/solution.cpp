class Solution {
public:
int dp[1001][1001], mod= 1e9 +7;
    int beautifulPartitions(string s, int k, int minLength) {
        // 11101101010
        
        memset(dp,-1,sizeof(dp));
        unordered_map<char,char> m ;
        for (int i='1'; i<='9'; i++){
            if (i=='2' || i=='3' || i=='5' || i=='7')
                m[i]='1';
            else
                m[i]='0';
        }
        int N=s.size();
        if (m[s[0]]=='0' || m[s[N-1]]=='1' ) return 0;
        for (auto &c : s) c = m[c];
 
        function<int(int,int)> dfs =  [&](int i,int K)->int{
            if (i>N)
                return 0;
            if (K==0) return 1;
            if (dp[i][K]!=-1) return dp[i][K];
            long ans = dfs(i+1,K);
            if (s[i]=='1' && s[i-1]=='0')  
                ans = (ans + dfs(i+minLength,K-1)) %mod;
            
            return dp[i][K] =ans;
        };
        return dfs(minLength,k-1);
    }
};