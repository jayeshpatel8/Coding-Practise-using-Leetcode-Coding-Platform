class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int N = nums.size();
        //if (k==0) return N==0? -1: nums[0];
        if (k<=1) return N<=k? -1: nums[k];
        if (N==1) return k&1 ? -1 : nums[0];
        if (N<=k-1) return *max_element(begin(nums),end(nums));
        return max(nums[k], *max_element(begin(nums),begin(nums) + min(k-1,N)));

    }
};