class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0 ,pair = 0;
        unordered_map<int,int> cnt;
        for (int i=0,j=0; i<nums.size() ; i++){
            pair += cnt[nums[i]]++;
            while ( pair >= k){
                ans += 1 + nums.size() - i - 1;
                pair -= --cnt[nums[j++]];
            }
        }
        return ans;
    }
};
