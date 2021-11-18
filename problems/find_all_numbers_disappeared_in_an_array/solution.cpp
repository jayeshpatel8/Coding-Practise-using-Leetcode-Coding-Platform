class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto i : nums){
            int idx = abs(i)-1;
            if (nums[idx] > 0)
                nums[idx] = -(nums[idx]);
        }
        vector<int> ans;
        for (int i=0; i<nums.size(); i++)
            if (nums[i] > 0)
                ans.push_back(i+1);
        return ans;
    }
};