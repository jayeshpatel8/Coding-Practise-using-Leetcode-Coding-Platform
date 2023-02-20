class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0 , r =  nums.size()-1;
        auto it =  lower_bound(begin(nums),end(nums),target);
        if (it == end(nums)) return nums.size();
        if (*it == target) return it - begin(nums);
        return (it - begin(nums));
    }
};