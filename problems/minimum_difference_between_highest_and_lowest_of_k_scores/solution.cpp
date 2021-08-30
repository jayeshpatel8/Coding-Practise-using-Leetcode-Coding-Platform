class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int i=k-1,j=0, diff=INT_MAX;
        for ( ; i<nums.size(); i++){
            diff = min(diff, nums[i] - nums[j++]);
        }
        return diff;
    }
};