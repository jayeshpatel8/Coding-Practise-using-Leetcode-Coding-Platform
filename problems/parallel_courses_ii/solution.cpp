class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dep(n, 0);
        for (auto& relation : relations) {
            int prev = relation[0] - 1, next = relation[1] - 1;
            dep[next] |= (1 << prev);
        }

        int totalState = 1 << n;
        vector<int> dp(totalState, n + 1);
        
        dp[0] = 0;
        for (int state = 0; state < totalState; state++) {
            if (dp[state] == n + 1) continue;
                
            int mask = 0;
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) continue;
                if ((state & dep[i]) != dep[i]) continue;
                mask |= (1 << i);
            }
                
            if (__builtin_popcount(mask) <= k) {
                dp[state | mask] = min(dp[state | mask], dp[state] + 1);
            } else {
                for (int subset = mask; subset; subset = (subset - 1) & mask) {
                    if (__builtin_popcount(subset) == k) {
                        dp[state | subset] = min(dp[state | subset], dp[state] + 1);
                    }
                }
            }
            
            if (dp[totalState - 1] != n + 1) return dp[totalState - 1];
        }
        return -1;
    }
    int minNumberOfSemesters2(int n, vector<vector<int>>& relations, int k) {
        vector<int> dep(n);
        for (auto r  : relations){
            dep[r[1]-1]  |= 1<<(r[0]-1);
        }
        vector<int> dep_mask(1 << n);
        for (int i=1; i<(1<<n); i++){
            for (int j=0; j<n; j++){
                if (i & 1<<j)
                    dep_mask[i] |= dep[j];
            }
        }   
        vector<int> dp(1 << n,n+1);
        dp[0] = 0;
        for (int i=1; i<(1<<n); i++){
            for (int j=i; j>0; j = (j-1) & i){
                if (__builtin_popcount(j) > k) continue;
                int finished  = i  ^ ((1<<n)-1);
                if ((finished & dep_mask[j]) == dep_mask[j]){
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};