class Solution {
public:
vector<int> primes,pmask;

int dp[1001][1024]={}, mod = 1e9 + 7;
    int squareFreeSubsets(vector<int>& nums) {
        primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        pmask.resize(31);
        memset(dp,-1,sizeof(dp));
        for (int i=2; i<31; i++){
            pmask[i] = getmask(i);
        }
        function<int(int,int)> dfs = [&](int i, int mask){
            if (i >= nums.size()) return 0;
            if (dp[i][mask] != -1) return dp[i][mask] ;
            int ans = ( dfs(i+1,mask));
            int newmask = pmask[nums[i]];
            if (newmask != -1 && (newmask & mask) ==0){
                ans = (ans + 1 + dfs(i+1,mask | newmask))%mod;
            }
            dp[i][mask]=ans;
            return dp[i][mask] ;
        };
        return dfs(0, 0);
    }
    int getmask(int num){
        int ans = 0;
        for (auto i=0; i<primes.size();i++){
            int cnt = 0;
            while(! (num % primes[i]))
                num /= primes[i], cnt++;
            if (cnt > 1) return -1;
            if (cnt)
                ans |= 1<<i;            
        }
        return ans;
    }
};