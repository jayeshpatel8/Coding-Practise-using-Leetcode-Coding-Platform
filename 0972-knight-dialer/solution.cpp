class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> valid = {{4,6},{6,8},{7,9},{4,8},{0,3,9},
                                   {},{0,1,7},{2,6},{1,3},{2,4}};
        vector<long> cur(10,1),next(10);
        long ans  = 0, mod = 1e9 + 7;
        for ( int i=1; i<n; i++){
            for (int j=0; j<=9; j++){
                next[j]=0;
                for (auto &c : valid[j])
                    next[j]  = (next[j] + cur[c])%mod;
            }
            swap(cur ,next);
        }
        
        for (auto i : cur) ans = (ans + i) % mod;
        return ans;
    }
};
