class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        for (auto i=1,m =nums[0]; i<nums.size(); i++){
            ans= max(ans, nums[i] - m);
            m = min(m, nums[i]);
        }
        return  ans <=0 ? -1 :ans;
    }
};
