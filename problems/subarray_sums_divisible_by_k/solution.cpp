class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k);
        cnt[0]=1;
        int prefix=0 ,ans=0;
        for (auto &i : nums){
            prefix = (prefix + i%k + k) %k;
            ans += cnt[prefix]++;
        }
        return ans;
    }
};