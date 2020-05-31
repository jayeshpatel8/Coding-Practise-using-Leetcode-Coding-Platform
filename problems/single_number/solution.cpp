class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 3) return nums[0];
        int xoring=nums[0];
        for (int i =1;i< nums.size();i++)
            xoring ^=nums[i];
        return xoring;
    }
};