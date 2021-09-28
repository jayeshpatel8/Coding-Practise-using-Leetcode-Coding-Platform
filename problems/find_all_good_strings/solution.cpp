class Solution {
public:
    int dp[501][51][2][2]={};
    int kmp[51]={}, e_sz, N,mod= 1e9 + 7;
    int findGoodStrings(int n, string s1, string s2, string evil) {
        // evil prefix match 
        e_sz  = evil.size();
        N = n;
        for(int i=1,j=0; i< e_sz; i++){
            while(j>0 && evil[i] !=evil[j]) j = kmp[j-1];
            if(evil[i] ==evil[j]) 
                kmp[i]=++j;
        }
        return dfs(s1,s2,0,0,true,true,evil);
    }
    int dfs(string&s1, string& s2, int i, int e, int start, int end, string& evil ){
        if (e == e_sz) return 0;
        if(i ==N) return 1;
        if(dp[i][e][start][end]) return dp[i][e][start][end];
        int ans = 0, from = start ? s1[i] : 'a', to = end ? s2[i] : 'z';
        
        for ( int ch = from; ch <= to; ch++){
            int j = e;
            while(j>0 && ch !=evil[j]) j = kmp[j-1];
            if (ch ==evil[j]) j++;
            ans = (ans + dfs(s1,s2,i+1,j,start && ch == from, end && ch==to,evil))%mod;
        }
        return dp[i][e][start][end] = ans;
    }
}; 