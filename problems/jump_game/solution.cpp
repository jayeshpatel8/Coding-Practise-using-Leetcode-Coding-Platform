class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 1;
        for (int j=nums[0]; j > 0 && i<nums.size(); i++){
            j = max(--j,nums[i] );
        }
        return i==nums.size();
    }
};