class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 1 1 1 2 2 3 4 4
        // 1 2 2 3 3 4 
        int n = nums.size();
        vector<int> dp;
              dp.push_back(nums[0]);
        for (int i=1; i<n; i++){
            int a = nums[i];
            if (dp.back() < a)
                dp.push_back(a);            
            else{
                auto e = lower_bound(dp.begin(), dp.end(),a);
                *e = a;
            }            
        }
        return dp.size();
    }
};