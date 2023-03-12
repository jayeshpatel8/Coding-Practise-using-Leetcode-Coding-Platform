class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> cnt;
        cnt[0]=1;
        int cur= 0;
        long long ans=0;
        for (auto i : nums){
            cur ^= i;
            ans += cnt[cur]++;
        }
        return ans;
    }
};