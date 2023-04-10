class Solution {
public:
    int maximumCount(vector<int>& nums) {
        return max (lower_bound(begin(nums),end(nums),0)-begin(nums),end(nums) - lower_bound(begin(nums),end(nums),1));
    }
};