class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        
        return min({*rbegin(nums) - *(begin(nums)+2), *(rbegin(nums)+2) - *(begin(nums)), *(rbegin(nums)+1) - *(begin(nums)+1)});
    }
};