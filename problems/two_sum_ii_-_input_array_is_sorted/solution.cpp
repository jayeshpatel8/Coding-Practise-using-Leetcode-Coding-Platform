class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0, j=nums.size()-1; 1; ){
            auto sum = nums[i] + nums[j];
            if (sum == target) return {i+1,j+1};
            else if(sum > target) j--;
            else i++;
        }
        return {};
    }
};