class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for ( int i=0;i<nums.size(); i++){
            int n = abs(nums[i])-1;
            if (nums[n] < 0){
                ans.push_back(n + 1);
            }
            else
                nums[n] = -nums[n];
        }
        return ans;
    }
};