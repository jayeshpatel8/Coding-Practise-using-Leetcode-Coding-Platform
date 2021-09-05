class Solution {
public:
    int N, mod= 1e9 + 7;
    int pfact[31]={}, freq[31]={};
    int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,31};
    unordered_map<size_t,size_t> dp;
    int numberOfGoodSubsets(vector<int>& nums) {
        N = nums.size();
        //memset(dp,-1,sizeof(dp));
        
        for (int i=2; i<31; i++){
            int n = i;
            for ( int k =0 ; primes[k]<=i; k++){                
                int cnt=0, j = primes[k];
                while(n%j ==0) cnt++, n/=j;
                if (cnt == 1)
                    pfact[i] |=1<<j;
                else if (cnt>1){
                    pfact[i] =(1UL<<31) - 1;
                    break;
                }                
            }
            
        }
        for (auto i : nums) freq[i]++;                             
        size_t ans = dfs(2,1)-1;
        if (ans && freq[1]) ans = (ans * binary_exp(2, freq[1]))%mod;
        return ans;
    }
    int dfs(int i, int mask){
        if (i>=31 ) return  1;
        size_t idx = ((size_t)i<<32) | mask;
        if (dp.count(idx)) return dp[idx];
        size_t ans = 0;
        if  (freq[i]){            
            if ((mask & pfact[i]) == 0){
                ans = (ans + (size_t)freq[i] * dfs(i+1,mask | pfact[i])) %mod;;
            }
        }
        ans = (ans  + dfs(i+1,mask)) %mod;
        return dp[idx] = ans;
    }
    size_t binary_exp(size_t i, int n){
        size_t ans = 1;
        while (n){
            if(n&1){
                ans =  ( ans * i) % mod;
                n--;
            }
            i = (i*i)%mod;
            n/=2;
        }
        return ans;
    }
};