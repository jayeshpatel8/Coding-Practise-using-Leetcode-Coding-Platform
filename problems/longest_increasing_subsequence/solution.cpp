class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        int ans=1;
        for (int i=1; i<nums.size(); i++){
            auto it  = lower_bound(begin(lis),end(lis),nums[i]);
            if (it == lis.end()) 
                lis.push_back(nums[i]),ans++;
            else
                *it = nums[i];
        }
        return ans;
    }
};