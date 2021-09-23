class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1);
        for (int i=0, left = 0; i<=n; i++){
            left = max(0, i - ranges[i]);
            dp[left] = max(dp[left],min(n,i + ranges[i]));
        }
        int r=dp[0], tap=1, m = 0;
        for (int l=0; l<=n;){                        
            if (r >= n) return tap;
            while (l<=r)
                m = max(m,dp[l++]);

            
            if (m < l)                
                return -1;
            
            tap++; r = m;
        }
        return tap;
    }
    /*
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+2,n+2);
        dp[0]=0;
        for( int i=0; i <=n; i++){
            int left = max(0,i-ranges[i]);
            for (int j = max(0,i-ranges[i]), right = min(n,i+ranges[i]); j<= right; j++)
                dp[j]  = min(dp[j], 1 +dp[left]);
        }
        return dp[n] < n+1 ? dp[n] : -1;
    }*/
};