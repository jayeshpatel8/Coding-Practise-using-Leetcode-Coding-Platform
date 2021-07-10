class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> lis;   
        lis.push_back(nums[0]);
        for (int i = 1; i<N; i++){
            auto it = lower_bound(begin(lis), end(lis),nums[i]);
            if (it == end(lis)) lis.push_back(nums[i]);
            else *it  = nums[i];
        }
        return lis.size();
    }
};