class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int dp[32]={0} ,x=0;
        for (auto i : nums){
            for (long j = 0; j<32; j++){
                if ((1UL << j) & i)
                    dp[j] += 1;
            }
            x ^=i;
        }
        long n = 0;
        for (int i=0; i<30; i++){
            if (dp[i] && dp[i] % 2 == 0)
                n |= (1UL<<i);
        }
     
        return x ^ n;
    }
};