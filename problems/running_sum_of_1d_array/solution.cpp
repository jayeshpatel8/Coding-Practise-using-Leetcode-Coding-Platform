class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> presum(nums.size());
        partial_sum(begin(nums), end(nums), begin(presum));
        return presum;
    }
};