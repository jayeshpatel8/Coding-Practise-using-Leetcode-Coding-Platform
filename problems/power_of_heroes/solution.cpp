class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int mod=1e9 + 7;
        long prev=0, ret = 0;
        sort(nums.begin(), nums.end());
        for (auto i : nums){
            long sq = ((long)i * i)%mod;
            ret= (ret + (sq * i) % mod + (prev * sq)%mod)%mod;
            prev=(prev*2+i)%mod;
        }
        return ret;
    }
};