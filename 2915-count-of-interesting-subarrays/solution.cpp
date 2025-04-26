class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long ans= 0 ;
        int psum=0;
        unordered_map<int,int> cnt;
        cnt[0]=1;
        for (auto i : nums){
            psum = (psum + (i % mod == k ? 1 : 0)) %mod;
            ans += cnt[(psum - k  + mod) % mod];
            cnt[psum]++;

        }
        return ans;
    }
};
